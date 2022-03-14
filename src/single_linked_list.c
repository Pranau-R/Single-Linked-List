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

struct node *head = NULL, *ptr;

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
        No arguments
        );

Description:
    It is a void function which returns no value. The character type argument is used here to store "strings" from user in a list.

Returns:
    Functions returning type void: Nothing.

*/

void add ()
    {
    char insert_name[20];

    printf("You selected Insertion of Name... \n");

    printf("Enter a Name you wish to Add: ");
    scanf("%s", insert_name);

    struct node *temp;

    temp = (struct node *) malloc (sizeof (struct node));
    strcpy(temp -> name, insert_name);

    if (head == NULL)
        {
        head = temp;
        temp -> next = NULL;
        }
    else
        {
        ptr = head;

        while(ptr -> next != NULL)
            {
            ptr = ptr -> next;
            }

        ptr -> next = temp;
        temp -> next = NULL;
        }
    }


/*

Name: delete()

Function:
    To delete a given name from the list.

Definition:
    void delete(
        No Arguments
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
    printf("Enter a Name you wish to delete: ");
    scanf("%s", delete_name);

    struct node *prev;

    ptr = head;
    prev = ptr;

    while (strcmp (delete_name, ptr -> name) != 0)
        {
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

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
void display (
        No Arguments
        );

Description:
    This function has no return value and no arguments. It is used to display the list whenever the function is called.

Returns:
    Functions returning type void: Nothing.

*/

void display()
    {
    ptr = head;
    printf("%s", ptr -> name);

    while ( ptr -> next != NULL)
        {
        ptr = ptr -> next;
        printf(" -> %s", ptr -> name);
        }

    printf("\n");
    printf("\n");
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

    int ch;

    printf("======== MENU ======== \n");
    printf("1. Add Entry: \n");
    printf("2. Delete Entry: \n");
    printf("3. Display Entries: \n");
    printf("4. exit \n");
    printf("\n");

    while(1)
        {
        printf("Enter the Choice: \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1:
                {
                add();
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
                break;
                }

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Entry!!\n");

                printf("\n");
            }
        }
    }