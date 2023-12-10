#ifndef LISTS_H
#define LISTS_H

#include "cells.h"

// Structure representing a list with a maximum level and an array of pointers to cells
typedef struct s_i_list {
    int max_level;          // Maximum level of the list
    t_i_cell* next[25];     // Array of pointers to cells in the list
} lvl_list;

/**
 * @brief Creates a new list
 * @param n_levels The number of levels in the list
 * @return A pointer to the newly created list
 */
lvl_list* cCreate_list(int n_levels);

/**
 * @brief Inserts a new cell with a specified value and number of levels into the list
 * @param value The value to be inserted into the cell
 * @param nb_levels The number of levels in the data structure
 * @param mylist The list in which the cell will be inserted
 */
void cInsert_B(int value, int nb_levels, lvl_list* mylist);

/**
 * @brief Displays the entire list with all levels and cells
 * @param mylist The list to be displayed
 */
void cDisplay_list(lvl_list* mylist);

/**
 * @brief Displays the list in a visually aligned format
 * @param mylist The list to be displayed
 */
void calligned_Display_list(lvl_list* mylist);

/**
 * @brief Displays the cells at a specific level in the list
 * @param mylist The list to be displayed
 * @param level The level to be displayed
 */
void cDisplay_level(lvl_list* mylist, int level);

/**
 * @brief Creates a list with a specified number of levels and a complex structure
 * @param n The number of levels in the list
 * @return A pointer to the newly created complex list
 */
lvl_list *complexity(int n);

/**
 * @brief Searches for a value in a list using a basic search algorithm
 * @param level_list The list to be searched
 * @param val The value to be searched for
 */
void clasic_search(lvl_list *level_list, int val);

/**
 * @brief Searches for a value in a list using an optimized search algorithm
 * @param level_list The list to be searched
 * @param val The value to be searched for
 */
void optimized_search(lvl_list *level_list, int val);

/**
 * @brief Updates the graph representation of the complecity on the csv file
 */
void UpdateGraph();

#endif // LISTS_H
