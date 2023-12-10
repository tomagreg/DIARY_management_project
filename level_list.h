#ifndef LEVEL_LIST_H
#define LEVEL_LIST_H

#include "contact.h"

// Structure representing a cell in a multi-level contact list
typedef struct s_d_cell {
    contact* contact;               // Contact data
    struct s_d_cell* next[15];      // Array of pointers to cells in the next level (maximum 15 levels)
} t_d_cell;

/**
 * @brief Creates a new cell with specified contact and number of levels
 * @param contact The contact data to be stored in the cell
 * @param nb_levels The number of levels in the data structure
 * @return A pointer to the newly created cell
 */
t_d_cell* Create_Cell(contact *contact, int nb_levels);

// Structure representing a multi-level contact list
typedef struct s_d_list {
    int max_level;                  // Maximum level of the list
    t_d_cell* heads[15];            // Array of pointers to the heads of cells in each level (maximum 15 levels)
} level_list;

/**
 * @brief Creates a new multi-level contact list with a specified number of levels
 * @param n_levels The number of levels in the list
 * @return A pointer to the newly created list
 */
level_list* Create_list(int n_levels);

/**
 * @brief Inserts a new contact at the beginning of the multi-level list
 * @param contact The contact to be inserted
 * @param nb_levels The number of levels of the cell to insert
 * @param mylist The list in which the contact will be inserted
 */
void Insert_B(contact* contact, int nb_levels, level_list* mylist);

/**
 * @brief Displays the entire multi-level list in a non aligned format
 * @param mylist The list to be displayed
 */
void softDisplay_level_list(level_list* mylist);

/**
 * @brief Displays the entire multi-level list
 * @param mylist The list to be displayed
 */
void Display_level_list(level_list* mylist);

/**
 * @brief Displays the cells at a specific level in the multi-level list
 * @param mylist The list to be displayed
 * @param level The level to be displayed
 */
void Display_level(level_list* mylist, int level);

/**
 * @brief Adds a new contact to the multi-level list
 * @param llist The list to which the contact will be added
 * @param newcontact The contact to be added
 */
void addContact(level_list *llist, contact *newcontact);

/**
 * @brief Converts a cell to a string
 * @param cell The cell to be converted
 * @return A string representation of the cell
 */
char *convert(t_cell *cell);



/**
 * @brief Loads a multi-level contact list from a file
 * @param FileName The name of the file from which the list will be loaded
 * @return A pointer to the loaded list
 */
level_list *load_list(const char *FileName);

/**
 * @brief Saves a multi-level contact list to a file
 * @param llist The list to be saved
 * @param FileName The name of the file to which the list will be saved
 */
void save_list(level_list *llist, const char *FileName);

/**
 * @brief Searches for a contact in the multi-level list
 * @param mylist The list to be searched
 * @return A pointer to the found contact
 */
contact *search_contact(level_list *mylist);

#endif // LEVEL_LIST_H

