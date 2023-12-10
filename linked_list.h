#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct s_cell
{
    char value;
    struct s_cell *next;
}t_cell;

typedef struct s_std_list
{
    t_cell *head;
} t_std_list;



t_std_list *Create_linked_List();
t_cell *CreateCCell(char val);
void addCell(char val, t_std_list *mylist);
void Display_llist(t_std_list *mylist);


#endif
