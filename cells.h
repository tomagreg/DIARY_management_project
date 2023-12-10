#ifndef CELLS_H
#define CELLS_H

// Structure representing a cell in a multi-level data structure
typedef struct i_cell {
    int value;                  // Value stored in the cell
    struct i_cell* next[15];    // Array of pointers to the next level cells (maximum 15 levels)
} t_i_cell;

/**
 * @brief Creates a new cell with the specified value and number of levels
 * @param value The value to be stored in the cell
 * @param nb_levels The number of levels in the data structure
 * @return A pointer to the newly created cell
 */
t_i_cell* cCreate_Cell(int value, int nb_levels);

#endif // CELLS_H