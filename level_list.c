#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "level_list.h"
#include "contact.h"

t_d_cell* Create_Cell(contact* contact, int nb_levels) {
    t_d_cell* new_cell = malloc(sizeof(t_d_cell));

    new_cell->contact = contact;

    for (int i = 0; i < nb_levels; i++) {
        new_cell->next[i] = NULL;
    }

    return new_cell;
}




level_list* Create_list(int n_levels) {
    level_list* newlist = malloc(sizeof(level_list));
    newlist->max_level = n_levels;
    for (int i = 0; i < n_levels; i++) {
        newlist->heads[i] = NULL;
    }

    return newlist;
}


void Insert_B(contact* contact,int nb_levels, level_list* mylist){
    t_d_cell* mycell = Create_Cell(contact, nb_levels);
    for (int i = 0; i < nb_levels; i++){
        mycell->next[i] = mylist ->heads[i];
        mylist->heads[i]=mycell;

    }

}
void Display_level(level_list* mylist, int level){
    t_d_cell *pt = mylist->heads[level];
    printf("Head %d -> ",level);
    while(pt != NULL){
        printf("|");
        Display_llist(pt->contact->name);
        printf("| ->");
        pt = pt->next[level];
    }
    printf("NULL \n");

}


void softDisplay_level_list(level_list* mylist){
    for(int i=0;i < mylist->max_level;i++){
        t_d_cell *pt = mylist->heads[i];
        printf("Head %d | -> ",i);
        while(pt != NULL){
            printf("|");
            Display_llist(pt->contact->name);
            printf("| ->");
            pt = pt->next[i];
        }
        printf("NULL \n");
    }

}

void Display_level_list(level_list* mylist){
    printf("[display begin]\n");
    if(mylist->heads[0] == NULL){
        for(int i = 0; i < 4;i++){
            printf("Head %d | -> NULL\n",i);
        }
    }else{
        for(int i=0;i < mylist->max_level;i++){

            t_d_cell *h0 = mylist->heads[0];
            t_d_cell *hi = mylist->heads[i];
            Display_llist(h0->contact->name);
            Display_llist(hi->contact->name);
            printf("\nHead %d |",i);

            while(h0 != NULL){

                if(hi != NULL && hi == h0){
                    printf("-->| ");
                    Display_llist(hi->contact->name);
                    printf("|");
                    hi=hi->next[i];
                }else{
                    t_cell *ptr = h0->contact->name->head;
                    printf("-------");
                    while(ptr!=NULL){
                        printf("-");
                        ptr = ptr->next;
                    }
                }
                h0 = h0->next[0];
            }
            printf("-->NULL\n");
        }
    }
}


void Display_keeper(t_d_cell *keeper[4], t_d_cell *prev){
    printf("prev :");
    Display_llist(prev->contact->name);
    printf("\n");
    for (int i = 0;i < 4 ;i++){
        Display_llist(keeper[i]->contact->name);
        if(keeper[i]->next[i] != NULL){
            printf(" ");
            Display_llist(keeper[i]->next[i]->contact->name);
        }
        printf("\n");
    }
}


void addContact(level_list *llist, contact *newcontact){

    t_d_cell *cell = Create_Cell(newcontact,4);
    int insertion_level;

    if(llist->heads[0] == NULL){ // Case where the level list is empty
        int i =0;

        while (llist->heads[i] == NULL && i < llist->max_level){
            llist->heads[i] = cell;
            i++;
        }

    }else {



        t_d_cell *temp = llist->heads[0]; // pointer which will browse through the level list
        t_d_cell *prev = llist->heads[0]; // pointer use to insert before temp pointer
        t_d_cell *keeper[4];// keep track of all the pointers at prev

        for (int i = 0; i < 4; i++) {//initialisation of the keeper
            keeper[i] = llist->heads[i];
        }


        if (temp != NULL ) {
            if (cell->contact->name->head->value < temp->contact->name->head->value) { // 1st letter < case

                for (int i = 0; i < 4; i++) {// place the contact in the first pos of the level list
                    cell->next[i] = llist->heads[i];
                    llist->heads[i] = cell;
                }

            } else if (cell->contact->name->head->value == temp->contact->name->head->value) { //1st lettre = case

                if (cell->contact->name->head->next->value <
                    temp->contact->name->head->next->value) { // 2nd letter < case

                    for (int i = 0; i < 4; i++) {// place the contact in the first pos of the level list
                        cell->next[i] = llist->heads[i];
                        llist->heads[i] = cell;
                    }

                    cell->next[3] = temp->next[3];// adjust the links between contacts
                    temp->next[3] = NULL;

                } else if (cell->contact->name->head->next->value ==
                           temp->contact->name->head->next->value) {// 2nd letter = case


                    if (cell->contact->name->head->next->value <
                        temp->contact->name->head->next->value) {//3rd letter < case

                        for (int i = 0; i < 4; i++) {// place the contact in the first pos of the level list
                            cell->next[i] = llist->heads[i];
                            llist->heads[i] = cell;
                        }
                        cell->next[3] = temp->next[3];// adjust the links between contacts
                        temp->next[3] = NULL;
                        cell->next[2] = temp->next[2];// adjust the links between contacts
                        temp->next[2] = NULL;

                    } else if (cell->contact->name->head->next->value >
                               temp->contact->name->head->next->value) {//3rd letter > case

                        for (int i = 0; i < 2; i++) {// place the contact at the second pos of the list at level 0 & 1
                            cell->next[i] = temp->next[i];
                            temp->next[i] = cell;
                        }

                    } else if (cell->contact->name->head->next->value ==
                               temp->contact->name->head->next->value) {//3rd letter = case

                        cell->next[0] = temp->next[0]; // place the contact at the second pos of the list at level 0
                        temp->next[0] = cell;

                    }

                } else if (cell->contact->name->head->next->value >
                           temp->contact->name->head->next->value) {// 2nd letter > case

                    for (int i = 0; i < 3; i++) {// place the contact at the second pos of the list at level 0, 1 & 2
                        cell->next[i] = temp->next[i];
                        temp->next[i] = cell;
                    }
                }
            } else if (cell->contact->name->head->value >
                       temp->contact->name->head->value) { // 1st letter > case => we have to browse throught the list
                printf("[16]\n");
                temp = temp->next[0];// the first letter case is finished

                for (int i = 0; i < 4; i++) {
                    keeper[i] = llist->heads[i];
                }//initialisation of the keeper



                while (temp != NULL && cell->contact->name->head->value > temp->contact->name->head->value) {

                    prev = temp;
                    temp = temp->next[3];// 1st letter != so we browse at level 3

                    for (int i = 0; i < 4; i++) { // actualisation of the keeper
                        if (prev->next[i] != NULL) {
                            Display_llist(prev->next[i]->contact->name);
                            keeper[i] = prev;
                        }
                    }
                }
                if (temp == NULL) {
                    for (int i = 0; i < 4; i++) { // actualisation of the keeper
                        if (keeper[i]->next[i] != NULL) {
                            //Display_llist(prev->next[i]->contact->name);
                            keeper[i] = keeper[i]->next[i];
                        }
                    }
                }


                if (temp == NULL || cell->contact->name->head->value <
                                    temp->contact->name->head->value) { //end of list or 1 letter before the one from temp




                    for (int i = 0; i < 4; i++) {  // place the contact at level 3
                        cell->next[i] = keeper[i];
                        keeper[i]->next[i] = cell;
                    }
                } else if (cell->contact->name->head->value ==
                           temp->contact->name->head->value) {// at the right position in level 3

                    while (temp != NULL && cell->contact->name->head->value == temp->contact->name->head->value
                           && cell->contact->name->head->next->value > temp->contact->name->head->next->value) {
                        //end of list or 1st letter before the one from temp or 2nd letter before the one from temp

                        prev = temp;
                        temp = temp->next[2];// 1st letter == so we browse at level 2

                        for (int i = 0; i < 3; i++) { // actualisation of the keeper
                            if (prev->next[i] != NULL) {
                                keeper[i] = prev;
                            }
                        }
                    }


                    if (temp == NULL || cell->contact->name->head->value < temp->contact->name->head->value
                        || cell->contact->name->head->next->value < temp->contact->name->head->next->value) {

                        for (int i = 0; i < 3; i++) {  // place the contact at level 2
                            cell->next[i] = keeper[i];
                            keeper[i]->next[i] = cell;
                        }


                        if (temp != NULL && cell->contact->name->head->value == temp->contact->name->head->value
                            && cell->contact->name->head->next->value < temp->contact->name->head->next->value
                            && temp->next[3] != NULL) {
                            // case where the cell inserted must be the one at level 3 (insertion before the first same letter)

                            cell->next[3] = temp->next[3];
                            temp->next[3] = NULL;
                        }

                    } else if (cell->contact->name->head->next->value == temp->contact->name->head->next->value) {

                        while (temp != NULL && cell->contact->name->head->value == temp->contact->name->head->value
                               && cell->contact->name->head->next->value == temp->contact->name->head->next->value
                               && cell->contact->name->head->next->next->value >
                                  temp->contact->name->head->next->next->value) {
                            //end of list or 1st letter before the one from temp or 2nd letter before the one from temp


                            prev = temp;
                            temp = temp->next[1];// 1st letter & 2nd letter == so we browse at level 1

                            for (int i = 0; i < 2; i++) { // actualisation of the keeper
                                if (prev->next[i] != NULL) {
                                    keeper[i] = prev;
                                }
                            }
                        }


                        if (temp == NULL || cell->contact->name->head->value < temp->contact->name->head->value
                            || cell->contact->name->head->next->value < temp->contact->name->head->next->value
                            || cell->contact->name->head->next->next->value <
                               temp->contact->name->head->next->next->value) {


                            for (int i = 0; i < 2; i++) {  // place the contact at level 1
                                cell->next[i] = keeper[i];
                                keeper[i]->next[i] = cell;
                            }

                            if (cell->contact->name->head->value == temp->contact->name->head->value
                                && cell->contact->name->head->next->value == temp->contact->name->head->next->value
                                &&
                                cell->contact->name->head->next->next->value <
                                temp->contact->name->head->next->next->value
                                && temp->next[3] != NULL) {
                                // case where the cell inserted must be the one at level 3 (insertion before the first same letter)


                                cell->next[3] = temp->next[3];
                                temp->next[3] = NULL;
                                cell->next[2] = temp->next[2];
                                temp->next[2] = NULL;
                            }

                        } else if (cell->contact->name->head->next->next->value ==
                                   temp->contact->name->head->next->next->value) {
                            cell->next[0] = temp->next[0];
                            temp->next[0] = cell;

                        }
                    }
                }
            }
        }
    }
}



char* convert(t_cell* cell) {
    char* values = malloc(4); // Allocate memory to store the concatenated string

    values[0] = cell->value;
    values[1] = cell->next->value;
    values[2] = cell->next->next->value;
    values[3] = '\0'; // Add null terminator to indicate the end of the string

    return values;
}




level_list *load_list(const char *FileName){
    level_list *lvl_list = Create_list(4);
    char purpose[100];
    int day, month, year, hhour, hminute, lhour, lminute;
    FILE *file = fopen(FileName,"r");
    if (file == NULL){
        printf("invalid file");
    }
    char ligne[1000];
    while (fgets(ligne, sizeof(ligne), file) != NULL) {

        a_std_list *app_list = Create_appointment_List();
        t_std_list *contact_name;

        char *token = strtok(ligne, ";");// divide the line into fields


        int count = 0;
        while (token != NULL) {//browse through columns

            if (count == 0) {// first column
                contact_name = transformString(token);
            }
            else if(token[0] != '\0'){// first column

                sscanf(token, "%d:%d:%d,%d:%d,%d:%d,%99[^,]",
                       &day, &month, &year, &hhour, &hminute, &lhour, &lminute, purpose);
                t_std_list *llpurpose = Create_linked_List();

                for(int i = 0;i< strlen(purpose);i++){
                    addCell(purpose[i], llpurpose);
                }

                appointement *newapp = NewAppointement(NewDate(day,month,year), NewHour(hhour,hminute), NewHour(lhour,lminute),llpurpose);
                fill_appointment_list(newapp,app_list);
                //Display_llist(contact_name);
                DisplayAppointement(newapp);
            }
            token = strtok(NULL, ";");
            count++;




        }
        contact *mycontact = NewContact(contact_name,app_list);
        addContact(lvl_list, mycontact);
        Display_level_list(lvl_list);
        //DisplayContact(mycontact);
        //addContact(lvl_list,mycontact);


    }
    fclose(file);
    return lvl_list;
}

void save_list(level_list *llist, const char *FileName ){

    FILE *file = fopen(FileName, "w+");
    if(llist->heads[0] == NULL){
        printf("List is empty, nothing to save");
    }else{

        t_d_cell *temp = llist->heads[0];
        while (temp->next[0] != NULL){//browse through contacts

            // adding the name of the contact
            t_cell *letter = temp->contact->name->head;
            while (letter != NULL){
                fprintf(file, "%c",letter->value);
                letter = letter->next;
            }



            //adding the details of the appontement
            if(temp->contact->appointments->head != NULL){
                a_cell *a_temp = temp->contact->appointments->head;
                while (a_temp != NULL){
                    fprintf(file, ";");
                    fprintf(file,"%d:%d:%d,%d:%d,%d:%d,",
                            a_temp->app->a_date->day,
                            a_temp->app->a_date->month,
                            a_temp->app->a_date->year,
                            a_temp->app->a_hour->hours,
                            a_temp->app->a_hour->minutes,
                            a_temp->app->a_length->hours,
                            a_temp->app->a_hour->minutes);

                    //adding the purpose of the appointement
                    t_cell *purpose = a_temp->app->purpose->head;
                    while (purpose != NULL){
                        fprintf(file, "%c",purpose->value);
                        purpose = purpose->next;
                    }
                    a_temp = a_temp->next;
                }
            }

            fprintf(file, "\n");
            temp = temp->next[0];
        }
    }



    fclose(file);

}

contact *search_contact(level_list *mylist){
    contact *c_list[100];
    char letters[4];
    if (mylist->heads[0] == NULL){
        printf("La liste est vide");
        return NULL;
    }else{
        printf("Entrer les 3 premières lettres du contact voulu : \n");
        scanf("%s",letters);
        t_d_cell *temp = mylist->heads[3];
        t_d_cell *prev = NULL;
        while(temp != NULL && temp->contact->name->head->value < letters[0]){
            prev = temp;
            temp = temp ->next[3];
        }
        if (temp == NULL || temp->contact->name->head->value > letters[0]){
            printf("No contact with such name on the list\n");
            return NULL;
        }else{
            while(temp != NULL && temp->contact->name->head->value == letters[0] && temp->contact->name->head->next->value < letters[1]){
                prev = temp;
                temp = temp ->next[2];
        }
            if (temp == NULL || temp->contact->name->head->value > letters[0] || temp->contact->name->head->next->value > letters[1]){
                printf("No contact with such name on the list\n");
                return NULL;
            }else{
                while(temp != NULL && temp->contact->name->head->value == letters[0] && temp->contact->name->head->next->value == letters[1]
                                                                                        && temp->contact->name->head->next->next->value < letters[2]){
                    prev = temp;
                    temp = temp ->next[1];

                }
                if (temp == NULL || temp->contact->name->head->value > letters[0] || temp->contact->name->head->next->value > letters[1] ||
                        temp->contact->name->head->next->next->value > letters[2]){
                    printf("No contact with such name on the list\n");
                    return NULL;
                }else{
                    int count = 0;
                    int choice;
                    printf("List of contacts starting whiwh name begin with %s\n",letters);
                    while(temp != NULL && temp->contact->name->head->value == letters[0] && temp->contact->name->head->next->value == letters[1]
                          && temp->contact->name->head->next->next->value == letters[2]){
                        c_list[count] = temp->contact;
                        printf("%d : ",count);
                        Display_llist(temp->contact->name);
                        printf("\n");
                        count ++;
                        temp = temp->next[0];
                    }
                    printf("Enter the number corresponding to the contact of your choice :\n");
                    do{scanf("%d",&choice);

                    } while (choice < 0 || choice > count);
                    return c_list[choice];
                }
            }
        }
    }
}


