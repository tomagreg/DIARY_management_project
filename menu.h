#ifndef MENU_H
#define MENU_H

#include "level_list.h"

/**
 * @brief Displays the main menu and handles user choices
 * @param lvl_list The multi-level contact list
 */
void MainMenu(level_list *lvl_list);

/**
 * @brief Displays the appointments of a selected contact
 * @param lvl_list The multi-level contact list
 */
void seeAppointement(level_list *lvl_list);

/**
 * @brief Displays the menu for adding a new appointment
 * @param lvl_list The multi-level contact list
 */
void AddApppointementMenu(level_list *lvl_list);

/**
 * @brief Imports contact data from a file into the multi-level contact list
 * @param lvl_list The multi-level contact list
 */
void import(level_list *lvl_list);

/**
 * @brief Exports contact data from the multi-level contact list to a file
 * @param lvl_list The multi-level contact list
 */
void export(level_list *lvl_list);

/**
 * @brief Displays the menu for adding a new contact
 * @param lvl_list The multi-level contact list
 */
void AddContact(level_list *lvl_list);

/**
 * @brief Displays the complexity of the multi-level contact list
 * @param lvl_list The multi-level contact list
 */
void showComplexity(level_list *lvl_list);

/**
 * @brief Navigates back to the main menu
 * @param lvl_list The multi-level contact list
 */
void Back(level_list *lvl_list);

#endif // MENU_H
