#include <stdlib.h>
#include "cells.h"

// Create a new integer cell with a specified value and number of levels
t_i_cell* cCreate_Cell(int value, int nb_levels) {
    // Allocate memory for the new cell
    t_i_cell* new_cell = malloc(sizeof(t_i_cell));

    // Set the value of the cell
    new_cell->value = value;

    // Initialize the next pointers for each level to NULL
    for (int i = 0; i < nb_levels; i++) {
        new_cell->next[i] = NULL;
    }

    // Return the newly created cell
    return new_cell;
}