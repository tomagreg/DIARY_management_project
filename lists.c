#include "lists.h"
#include "cells.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "timer.h"

// Create a new level list with a specified number of levels
lvl_list* cCreate_list(int n_levels) {
    // Allocate memory for the new list
    lvl_list* newlist = malloc(sizeof(lvl_list));

    // Set the maximum level for the list
    newlist->max_level = n_levels;

    // Initialize the next pointers for each level to NULL
    for (int i = 0; i < n_levels; i++) {
        newlist->next[i] = NULL;
    }

    // Return the newly created list
    return newlist;
}

// Insert a new cell with a specified value and number of levels into the list
void cInsert_B(int value, int nb_levels, lvl_list* mylist) {
    // Create a new cell
    t_i_cell* mycell = cCreate_Cell(value, nb_levels);

    // Connect the new cell to the list at each level
    for (int i = 0; i < nb_levels; i++) {
        mycell->next[i] = mylist->next[i];
        mylist->next[i] = mycell;
    }
}

// Display the elements at a specific level of the list
void cDisplay_level(lvl_list* mylist, int level) {
    t_i_cell* pt = mylist->next[level];
    printf("Head %d -> ", level);
    while (pt != NULL) {
        printf("%d -> ", pt->value);
        pt = pt->next[level];
    }
    printf("NULL \n");
}

// Display the entire list with all levels
void cDisplay_list(lvl_list* mylist) {
    for (int i = 0; i < mylist->max_level; i++) {
        t_i_cell* pt = mylist->next[i];
        printf("Head %d | -> ", i);

        while (pt != NULL) {
            printf("%d -> ", pt->value);
            pt = pt->next[i];
        }
        printf("NULL \n");
    }
}

// Display the list with aligned columns for each level
void calligned_Display_list(lvl_list* mylist) {
    for (int i = 0; i < mylist->max_level; i++) {
        t_i_cell* h0 = mylist->next[0];
        t_i_cell* hi = mylist->next[i];
        printf("Head %d |", i);

        while (h0 != NULL) {
            if (hi != NULL && h0->value == hi->value) {
                printf("-->|%d|", h0->value);
                hi = hi->next[i];
            } else {
                if (h0->value > 9) {
                    printf("-------");
                } else if (h0->value > 99) {
                    printf("--------");
                } else {
                    printf("------");
                }
            }
            h0 = h0->next[0];
        }
        printf("-->NULL\n");
    }
}

// Create a list with a specific complexity based on the number of levels
lvl_list* complexity(int n) {
    int N = pow(2, n) - 1;
    int levels[N];

    for (int i = 0; i < N; i++) {
        levels[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j++) {
            if ((j + 1) % (int)pow(2, i) == 0) {
                levels[j] += 1;
            }
        }
    }

    lvl_list* mylist = cCreate_list(n);

    for (int i = N - 1; i >= 0; i--) {
        cInsert_B(i, levels[i], mylist);
    }

    return mylist;
}

// Perform a classical search on the list for a given value
void clasic_search(lvl_list* level_list, int val) {
    t_i_cell* temp = level_list->next[0];
    while (temp != NULL && temp->value != val) {
        temp = temp->next[0];
    }
}

// Perform an optimized search on the list for a given value
void optimized_search(lvl_list* level_list, int val) {
    int actual_lvl = level_list->max_level - 1;
    t_i_cell* temp = level_list->next[actual_lvl];
    t_i_cell* prev = NULL;

    while (temp != NULL && temp->value != val) {
        if (temp->value < val) {
            if (temp->next[actual_lvl] == NULL) {
                actual_lvl--;
            }
            prev = temp;
            temp = temp->next[actual_lvl];
        } else if (temp->value > val) {
            if (prev == NULL) {
                actual_lvl--;
                temp = level_list->next[actual_lvl];
            } else {
                actual_lvl--;
                temp = prev->next[actual_lvl];
            }
        }
    }
}

// Update the graph and measure search times for different complexities
void UpdateGraph() {
    srand(time(NULL));
    lvl_list* mylist = complexity(18);

    FILE* file = fopen("data1.csv", "w");

    int liste[] = {1000, 10000, 100000};

    for (int j = 0; j < 3; j++) {
        printf("%d\n", liste[j]);
        fprintf(file, "classical %d searches;", liste[j]);
        for (int n = 1; n < 15; n++) {
            startTimer();
            for (int k = 0; k < liste[j]; k++) {
                int randint = rand() % (int)round(pow(2.0, n) - 1) + 1;
                clasic_search(mylist, randint);
            }
            stopTimer();
            fprintf(file, "%s;", getTimeAsString());
        }
        fprintf(file, "\n");
        fprintf(file, "optimized %d searches;", liste[j]);
        for (int n = 1; n < 15; n++) {
            startTimer();
            for (int k = 0; k < liste[j]; k++) {
                int randint = rand() % (int)round(pow(2.0, n) - 1) + 1;
                optimized_search(mylist, randint);
            }

            stopTimer();
            fprintf(file, "%s;", getTimeAsString());
        }
        fprintf(file, "\n");
    }
    printf("[END]");
}
