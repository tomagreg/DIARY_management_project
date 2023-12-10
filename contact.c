#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "date.h"
#include "linked_list.h"

// Formatting for display characters
void formating(char cara[]) {
    for (int i = 0; cara[i] != '\0'; ++i) {
        // Replace special characters with specific ASCII values
        if (cara[i] == '#')
            cara[i] = 219;  // █

        if (cara[i] == 'A')
            cara[i] = 201;  // ╔

        if (cara[i] == 'D')
            cara[i] = 200;  // ╚

        if (cara[i] == 'B')
            cara[i] = 187;  // ╗

        if (cara[i] == 'C')
            cara[i] = 188;  // ╝

        if (cara[i] == 'V')
            cara[i] = 186;  // ║

        if (cara[i] == 'H')
            cara[i] = 205;  // ═

        if (cara[i] == 'N')
            cara[i] = 196;  // ─

        if (cara[i] == 'X')
            cara[i] = 192;  // └

        if (cara[i] == 'M')
            cara[i] = 179;  // │

        if (cara[i] == 'L')
            cara[i] = 217;  // ┘

        if (cara[i] == 'K')
            cara[i] = 218;  // ┌

        if (cara[i] == 'J')
            cara[i] = 191;  // ┐

        if (cara[i] == 'G')
            cara[i] = 194;  // ┬

        if (cara[i] == 'F')
            cara[i] = 193;  // ┴

        if (cara[i] == '_')
            cara[i] = ' ';  // ' '
    }
}

// Transform string for a linked list
t_std_list *transformString(char mystr[500]) {
    int x = 0;
    int i = 0;
    t_std_list *mylist = Create_linked_List();

    while (x < 2 && i <= strlen(mystr)) {
        if (mystr[i] != '\0' && mystr[i] != '\n') {
            if (mystr[i] >= 65 && mystr[i] <= 90) {
                addCell(mystr[i] + 32, mylist);
            } else if (mystr[i] == 32) {
                addCell('_', mylist);
            } else {
                addCell(mystr[i], mylist);
            }
            x = 0;
        } else {
            x++;
        }
        i++;
    }
    return mylist;
}

// Scan a string and transform it into a linked list
t_std_list *scanString() {
    char mystr[500] = {0};
    scanf(" %[^\n]", mystr);
    return transformString(mystr);
}

// Appointment Management

// Create a new appointement
appointement *CreateAppointement() {
    printf("\nSet the DATE of your appointement\n");
    date *a_date = CreateDate();

    printf("\nSet the HOUR of the appointement\n");
    hour *a_hour = CreateHour();

    printf("\nSet the LENGTH of the appointement\n");
    hour *length = CreateHour();

    printf("\nEnter the PURPOSE of the appointement\n");
    t_std_list *purpose = scanString();
    appointement *myapp = NewAppointement(a_date, a_hour, length, purpose);
    return myapp;
}

// Create a new appointement
appointement *NewAppointement(date *a_date, hour *a_hour, hour *length, t_std_list *purpose) {
    appointement *myapp = malloc(sizeof(appointement));
    myapp->a_date = a_date;
    myapp->a_hour = a_hour;
    myapp->a_length = length;
    myapp->purpose = purpose;
    return myapp;
}

// Create an appointment list
a_std_list *Create_appointment_List() {
    a_std_list *mylist = malloc(sizeof(a_std_list));
    mylist->head = NULL;
    return mylist;
}

// Fill an appointment list with an appointment
void fill_appointment_list(appointement *app, a_std_list *app_list) {
    a_cell *cell = malloc(sizeof(a_cell));
    cell->app = app;

    if (app_list->head == NULL) {
        app_list->head = cell;
    } else {
        a_cell *temp = app_list->head;
        while (temp != NULL) {
            DisplayAppointement(temp);
            temp = temp->next;
        }
        app_list->head->next = cell;
    }
}

// Create a new contact
contact *NewContact(t_std_list *name, a_std_list *appointements) {
    contact *mycontact = malloc(sizeof(contact));
    mycontact->name = name;
    mycontact->appointments = appointements;
    return mycontact;
}

// Create a new contact
contact *CreateContact() {
    printf("\nEnter the Surname and Firstname of your contact : ");
    t_std_list *name = scanString();
    a_std_list *appointements = Create_appointment_List();
    printf("\n");
    contact *newcontact = NewContact(name, appointements);
    return newcontact;
}

// Display an appointement
void DisplayAppointement(appointement *myapp) {
    char top[] = "KNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNJ\n";
    char bot[] = "XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNL\n";
    formating(top);
    formating(bot);
    printf("%s", top);
    char side[] = "M";
    formating(side);
    printf("%s ", side);
    printf("%02d/%02d/%04d at %02d:%02d for %02d hours and %02d minutes",
           myapp->a_date->day, myapp->a_date->month, myapp->a_date->year,
           myapp->a_hour->hours, myapp->a_hour->minutes,
           myapp->a_length->hours, myapp->a_length->minutes);
    printf("              %s\n", side);
    printf("%s", bot);
    printf("  PURPOSE : ");
    Display_llist(myapp->purpose);
    printf("\n\n");
}

// Display an appointment list
void DisplayAppointementList(contact *mycontact) {
    if (mycontact->appointments != NULL && mycontact->appointments->head != NULL) {
        a_cell *cell = mycontact->appointments->head;
        while (cell != NULL) {
            DisplayAppointement(cell->app);
            cell = cell->next;
        }
    } else {
        printf("This contact has no appointment \n");
    }
}

// Delete an appointement from the list
void deleteAppointement(appointement *app, a_std_list *a_list) {
    a_cell *temp = a_list->head;
    if (app == a_list->head->app) {
        a_list->head = a_list->head->next;
    } else {
        a_cell *prev = a_list->head;
        while (temp->app != app) {
            temp = temp->next;
        }
        prev->next = temp->next;
    }
    free(app);
}

// Display a contact
void DisplayContact(contact *mycontact) {
    char top[] = "KNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNJ\n";
    char bot[] = "XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNL\n";
    char side[] = "M";
    formating(side);
    formating(top);
    formating(bot);

    printf("%s", top);
    printf("%s", side);
    t_cell *temp = mycontact->name->head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    int size = 61 - len;

    int f_part;

    if (size % 2 != 0) {
        f_part = (size + 1) / 2;
    } else {
        f_part = size / 2;
    }
    for (int i = 0; i < f_part; i++) {
        printf(" ");
    }
    Display_llist(mycontact->name);
    for (int i = 0; i < (size / 2); i++) {
        printf(" ");
    }
    printf("%s\n", side);
    printf("%s", bot);
    if (mycontact->appointments->head != NULL) {
        a_cell *app = mycontact->appointments->head;
        while (app != NULL) {
            DisplayAppointement(app->app);
            app = app->next;
        }
    }
}
