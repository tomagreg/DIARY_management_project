#ifndef DATE_H
#define DATE_H

// Structure representing an hour with hours and minutes
typedef struct s_hour {
    int hours;      // Hours component of the time
    int minutes;    // Minutes component of the time
} hour;

// Structure representing a date with day, month, and year
typedef struct s_date {
    int day;        // Day component of the date
    int month;      // Month component of the date
    int year;       // Year component of the date
} date;

/**
 * @brief Creates a new date with users values
 * @return A pointer to the newly created date
 */
date* CreateDate();

/**
 * @brief Creates a new date with specified day, month, and year
 * @param day The day component of the date
 * @param month The month component of the date
 * @param year The year component of the date
 * @return A pointer to the newly created date
 */
date* NewDate(int day, int month, int year);

/**
 * @brief Creates a new hour with users values
 * @return A pointer to the newly created hour
 */
hour* CreateHour();

/**
 * @brief Creates a new hour with specified hours and minutes
 * @param hours The hours component of the time
 * @param minutes The minutes component of the time
 * @return A pointer to the newly created hour
 */
hour* NewHour(int hours, int minutes);

#endif // DATE_H