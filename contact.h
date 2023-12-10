#ifndef CONTACT_H
#define CONTACT_H

#include "date.h"
#include "linked_list.h"

// Structure representing an appointment with date, start time, duration, and purpose
typedef struct s_appointment {
    date *a_date;           // Date of the appointment
    hour *a_hour;           // Start time of the appointment
    hour *a_length;         // Duration of the appointment
    t_std_list *purpose;    // Purpose or description of the appointment
} appointement;

// Structure representing a cell in an appointment linked list
typedef struct s_appointment_cell {
    appointement *app;              // Appointment data
    struct s_appointment_cell *next; // Pointer to the next appointment cell
} a_cell;

// Structure representing an appointment linked list
typedef struct s_appointment_list {
    a_cell *head;   // Head of the appointment list
} a_std_list;

// Structure representing a contact with a name and a list of appointments
typedef struct s_contact {
    t_std_list *name;           // Name of the contact
    a_std_list *appointments;   // List of appointments for the contact
} contact;

/**
 * @brief Scans a string input and returns a linked list
 * @return A pointer to the standardized list
 */
t_std_list *scanString();

/**
 * @brief Transforms a string into normalized characters
 * @param mystr The input string
 * @return A pointer to the standardized list
 */
t_std_list *transformString(char mystr[500]);

/**
 * @brief Formats a character array
 * @param cara The character array to be formatted
 */
void formating(char cara[]);

/**
 * @brief Creates a new appointment with users values
 * @return A pointer to the newly created appointment
 */
appointement *CreateAppointement();

/**
 * @brief Creates a new appointment with specified date, start time, duration, and purpose
 * @param date The date of the appointment
 * @param ahour The start time of the appointment
 * @param length The duration of the appointment
 * @param purpose The purpose or description of the appointment
 * @return A pointer to the newly created appointment
 */
appointement *NewAppointement(date *date, hour *ahour, hour *length, t_std_list *purpose);

/**
 * @brief Creates a new appointment list with a null head
 * @return A pointer to the newly created appointment list
 */
a_std_list *Create_appointment_List();

/**
 * @brief Creates a new contact with specified name and appointment list
 * @param name The name of the contact
 * @param appointements The list of appointments for the contact
 * @return A pointer to the newly created contact
 */
contact *CreateContact();

/**
 * @brief Creates a new contact with specified name and appointment list
 * @param name The name of the contact
 * @param appointements The list of appointments for the contact
 * @return A pointer to the newly created contact
 */
contact *NewContact(t_std_list *name, a_std_list *appointements);

/**
 * @brief Fills an appointment list with a given appointment
 * @param app The appointment to be added to the list
 * @param app_list The list to which the appointment will be added
 */
void fill_appointment_list(appointement *app, a_std_list *app_list);

/**
 * @brief Displays the details of a single appointment
 * @param myapp The appointment to be displayed
 */
void DisplayAppointement(appointement *myapp);

/**
 * @brief Displays the list of appointments for a contact
 * @param mycontact The contact whose appointments will be displayed
 */
void DisplayAppointementList(contact *mycontact);

/**
 * @brief Deletes a specific appointment from the appointment list
 * @param app The appointment to be deleted
 * @param a_list The list from which the appointment will be deleted
 */
void deleteAppointement(appointement *app, a_std_list *a_list);

/**
 * @brief Displays the details of a contact, including their name and appointments
 * @param mycontact The contact to be displayed
 */
void DisplayContact(contact *mycontact);

#endif // CONTACT_H
