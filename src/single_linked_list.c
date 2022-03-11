/*

Module: single_linked_list.c

Function:
    To create a Menu to add, delete and display names in a linked list.

Copyright notice:
    This file copyright (C) 2022 by

    MCCI Corporation
    3520 Krums Corners Road
    Ithaca, NY 14850

    An unpublished work. All rights reserved.

    This file is proprietary information, and may not be disclosed or
    copied without the prior permission of MCCI Corporation.

Author:
    Pranau R, MCCI Corporation   March 2022

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
    {
    char name[20];
    struct node *next;
    };

struct node *head, *ptr;

/****************************************************************************\
|
|   Functions.
|
\****************************************************************************/

/*

Name: add()

Function:
    To add new names on the list.

Definition:
    void add (
        char name[20], character array of size 20 to store string data
        );

Description:
    It is a void function which returns no value. The character type argument is used here to store "strings" from user in a list.

Returns:
    Functions returning type void: Nothing.

*/

void add ()
    {
    char insert_name[20];
    /*printf("Enter the Name : ");
    scanf("%s",nm);*/

    printf("You selected Insertion of Name... \n");

    printf("Enter the Name : ");
    scanf("%s", insert_name);

    struct node *temp;
    //temp = head;

    temp = (struct node *) malloc (sizeof (struct node));
    temp -> next = NULL;
    strcpy(temp -> name, insert_name);

    /*printf("The address of temp before cond: %p \n", temp);

    printf("The address of ptr before cond: %p \n", ptr);

    printf("the names is: %s \n", nm);*/

    if (head == NULL)
        {
        head = temp;
        /*printf("The address of temp after if cond: %p \n", temp);

        printf("The address of ptr after if cond: %p \n", ptr);*/
        }
    else
        {
        ptr = head;
        //printf("The address of ptr after ptr = head: %p \n", ptr);

        while(ptr -> next != NULL)
            {
            ptr = ptr -> next;
            }

        ptr -> next = temp;
        temp -> next = NULL;

        //printf("The address of temp after else cond: %p \n", temp);

        //printf("The address of ptr after else cond: %p \n", ptr);
        }
    }


/*

Name: delete()

Function:
    To delete a given name from the list.

Definition:
    void delete(
        char delete_name[20], character array of size 20 to get string value from user for deletion purpose
        );

Description:
    It is a void function which returns no value. The character type argument is used to store "string"
    for comparing with main list of string and to delete the matching string.

Returns:
    Functions returning type void: Nothing.

*/

void delete()
    {
    char delete_name[20];

    printf("You selected Deletion of Name... \n");
    printf("Enter a Name you wish to delete: \n");
    scanf("%s", delete_name);

    /*printf("Enter the Name need to be deleted: ");
    fgets(del, sizeof(del), stdin);*/

    //printf("%s\n", del);
    //printf("The name to be deleted is: %s \n", delete_name);

    //printf("The address of ptr before cond: %p \n", ptr);

    /*if (head == NULL)
        {
        printf("List is Empty, Deletion is not Possible!!\n");
        }
    else
        {*/

    struct node *prev;

    ptr = head;
    prev = ptr;

    /*printf("The address of ptr after else cond: %p \n", ptr);

    printf("The address of prev after prev = ptr cond: %p \n", prev);

    int comp = strcmp (ptr -> name, delete_name);
    printf("strcmp OP is: %d \n", comp);*/

    while (strcmp (delete_name, ptr -> name) != 0)
        {
        //printf("The address of ptr inside while cond: %p \n", ptr);

        if(ptr -> next == NULL)
            {
            printf("The name you entered is not present in the List!!\n");
            break;
            }
        else
            {
            prev = ptr;
            ptr = ptr -> next;
            }
        //prev = ptr;
        }

    if (ptr == head)
        {
        head = ptr -> next;
        }
    else
        {
        prev -> next = ptr -> next;
        }
    
    free (ptr);
    ptr = NULL;
    }
        //printf("The address of p after while loop: %p \n", prev);
        /*printf("The address of p after p -> next: %p \n", prev);

        printf("The address of ptr after free: %p \n", ptr);*/

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
void display (void);

Description:
    This function has no return value and no arguments. It is used to display the list whenever the function is called.

Returns:
    Functions returning type void: Nothing.

*/

void display()
    {
        if (head == NULL)
            {
            printf("\n");
            }
        else
            {
            ptr = head;
            while ( ptr -> next != NULL)
                {
                //printf("-> ");
                //puts(ptr -> name[20]);
                printf("-> %s", ptr -> name);
                ptr = ptr -> next;
                }

            printf("\n");
            }
    }

/****************************************************************************\
|
|   Code.
|
\****************************************************************************/

void main()
    {
    void add();
    void delete();
    void display();

    //char insert_name[20], delete_name[20];
    int ch;

    printf("1. Add Entry: \n");
    printf("2. Delete Entry: \n");
    printf("3. Display Entries: \n");
    printf("4. exit \n");

    while(1)
        {
        printf("Enter the Choice: \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1:
                {
                add();
                //printf("The list after addition is: \n");

                display();
                break;
                }

            case 2:
                {
                if (head == NULL)
                    {
                    printf("List is Empty, Deletion is not Possible!!\n");
                    }
                else
                    {
                    delete();
                    display();
                    }

                //printf("The list after deletion is: \n");
                break;
                }

            case 3:
                display();

            case 4:
                exit(0);

            default:
                printf("Invalid Entry!!\n");

                printf("\n");
                break;
            }
        }
    }