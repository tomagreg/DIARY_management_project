#include <stdio.h>
#include <stdlib.h>
#include "date.h"

// Function to create a date
date* CreateDate() {
    int day;
    int month;
    int year;

    do {
        printf("Enter the day number:");
        scanf("%d", &day);
    } while (day <= 0 || day > 31);

    do {
        printf("Enter the month number:");
        scanf("%d", &month);
    } while (month <= 0 || month > 12);

    do {
        printf("Enter the year:");
        scanf("%d", &year);
    } while (year < 2020 || year > 3000);

    date *mydate = NewDate(day, month, year);
    return mydate;
}

// Function to initialize a date
date *NewDate(int day, int month, int year) {
    date* mydate = malloc(sizeof(date));
    mydate->day = day;
    mydate->month = month;
    mydate->year = year;
    return mydate;
}

// Function to create an hour
hour* CreateHour() {
    int hours;
    int minutes;

    do {
        printf("Enter the number of hours :");
        scanf("%d", &hours);
    } while (hours < 0 || hours > 23);

    do {
        printf("Enter the number of minutes :");
        scanf("%d", &minutes);
    } while (minutes < 0 || minutes > 59);

    hour *myhour = NewHour(hours, minutes);
    return myhour;
}

// Function to initialize an hour
hour *NewHour(int hours, int minutes) {
    hour* myhour = malloc(sizeof(hour));
    myhour->hours = hours;
    myhour->minutes = minutes;
    return myhour;
}
