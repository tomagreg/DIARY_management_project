#include <stdio.h>
#include <stdlib.h>
#include "level_list.h"
#include "menu.h"
#include "lists.h"

void Back(level_list *lvl_list){
    int a;
    do{
        printf("Enter 1 to go back to  the main menu : \n");
        scanf("%d",&a);
    } while (a != 1);
    MainMenu(lvl_list);

}
// Function to display appointments of a contact
void seeAppointement(level_list *lvl_list) {
    DisplayAppointementList(search_contact(lvl_list));
    Back(lvl_list);
}

// Function to add an appointment to a contact
void AddApppointementMenu(level_list *lvl_list) {
    fill_appointment_list(CreateAppointement(), search_contact(lvl_list)->appointments);
    Back(lvl_list);
}

// Function to import contacts from a CSV file
void import(level_list *lvl_list) {
    lvl_list = load_list((const char *)scanf("Enter the name of the file .csv to be loaded : "));
    Back(lvl_list);
}

// Function to export contacts to a CSV file
void export(level_list *lvl_list) {
    save_list(lvl_list, (const char *)scanf("Enter the name of the file .csv to save the Diary :"));
    Back(lvl_list);
}

// Function to show complexity of search operations
void showComplexity(level_list *lvl_list) {
    UpdateGraph();
    printf("Check the Excel file on the debug folder to compare the differences in complexity\n"
           "between a search at the level 0 or a dichotomic search\n");
    Back(lvl_list);
}

// Function to add a contact to the list
void AddContact(level_list *lvl_list) {
    addContact(lvl_list, CreateContact());
    Back(lvl_list);
}

void MainMenu(level_list *lvl_list){

    char menu[] =
            "                   AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHB\n"
            "                   V                                                                      V\n"
            "                   V      ##    ##  ##    ##   #####   ##   #####   ######  ##    ##      V\n"
            "                   V      ########   ##  ##    ##  ##      ##   ##  ##   ##  ##  ##       V\n"
            "                   V      ## ## ##    ####     ##  ##  ##  #######  ######    ####        V\n"
            "                   V      ##    ##     ##      ##  ##  ##  ##   ##  ##   ##    ##         V\n"
            "                   V      ##    ##     ##      #####   ##  ##   ##  ##   ##    ##         V\n"
            "                   V                                                                      V\n"
            "                   DHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHC\n\n\n"
            "                                       What do you want to do ?\n\n\n"
            "                     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ\n"
            "                     M 1 M see appointments        M     M 4 M import a contact list   M\n"
            "                     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL\n\n"
            "                     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ\n"
            "                     M 2 M add appointments        M     M 5 M export a contact list   M\n"
            "                     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL\n\n"
            "                     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ     KNNNGNNNNNNNNNNNNNNNNNNNNNNNNNJ\n"
            "                     M 3 M add a contact           M     M 6 M show complexity         M\n"
            "                     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL     XNNNFNNNNNNNNNNNNNNNNNNNNNNNNNL\n\n";


    formating(menu);
    printf("%s",menu);
    int a;
    do{
        scanf("%d",&a);
    } while (a < 1 || a > 6);
    printf("%d",a);
    switch (a) {
        case 1:
            printf("");
            seeAppointement(lvl_list);
            break;
        case 2:
            AddApppointementMenu(lvl_list);
            break;
        case 3:
            AddContact(lvl_list);
            break;
        case 4:
            import(lvl_list);
            break;
        case 5:
            export(lvl_list);
            break;
        case 6:
            showComplexity(lvl_list);
    }
}
