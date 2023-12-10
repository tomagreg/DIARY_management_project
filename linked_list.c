#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create an empty standard linked list
t_std_list *Create_linked_List() {
    t_std_list *mylist = malloc(sizeof(t_std_list));
    mylist->head = NULL;
    return mylist;
}

// Create a new character cell with a specified value
t_cell *CreateCCell(char val) {
    t_cell *mycel = malloc(sizeof(t_cell));
    mycel->value = val;
    mycel->next = NULL;
    return mycel;
}

// Add a new cell with a specified value to the end of the linked list
void addCell(char val, t_std_list *mylist) {
    t_cell *newcell = CreateCCell(val);
    if (mylist->head == NULL) {
        mylist->head = newcell;
    } else {
        t_cell *temp = mylist->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newcell;
    }
}

// Display the contents of the linked list
void Display_llist(t_std_list *mylist) {
    if (mylist->head != NULL) {
        t_cell *temp = mylist->head;
        while (temp != NULL) {
            printf("%c", temp->value);
            temp = temp->next;
        }
        printf(" ");
    }
}
