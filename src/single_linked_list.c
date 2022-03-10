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
    VOID add (
        CHAR name[20], character array of size 20 to store string data
        );

Description:
    It is a void function which returns no value. The character type argument is used here to store "strings" from user in a list.

Returns:
    Functions returning type void: Nothing.

*/

void add (char nm[20])
    {
    /*int val[20];

    val[20];

    val[21] = 1;
    printf("%d\n", val[21]);*/

    /*printf("Enter the Name : ");
    scanf("%s",nm);*/

    printf("You selected Insertion of Name... \n");
    printf("Now Enter the Name: ");
	scanf("%s", nm);

    struct node *temp;

    printf("The address of temp before memory alloc: %p \n", temp);

	temp = (struct node *) malloc (sizeof (struct node));

    printf("The address of temp after malloc: %p \n", temp);

    //printf("%s\n", nm);
	//temp -> name[20];
    temp -> next = NULL;
    strcpy(temp -> name, nm);
    //strcpy(nm, name);

    printf("The address of temp before cond: %p \n", temp);

    printf("The address of ptr before cond: %p \n", ptr);

    printf("the names is: %s \n", nm);

    if (head == NULL)
	    {
		head = temp;
        printf("The address of temp after if cond: %p \n", temp);

        printf("The address of ptr after if cond: %p \n", ptr);
	    }
    else
        {
        ptr = head;
        printf("The address of ptr after ptr = head: %p \n", ptr);

		while(ptr -> next != NULL)
		    {
			ptr = ptr -> next;
		    }

		ptr -> next = temp;
		temp -> next = NULL;

        printf("The address of temp after else cond: %p \n", temp);

        printf("The address of ptr after else cond: %p \n", ptr);
        }
    }

/*

Name: delete()

Function:
    To delete a given name from the list.

Definition:
    VOID delete(
        CHAR del[20], character array of size 20 to get string value from user for deletion purpose
        );

Description:
    It is a void function which returns no value. The character type argument is used to store "string"
    for comparing with main list of string and to delete the matching string.

Returns:
    Functions returning type void: Nothing.

*/

void delete(char del[20])
    {
    /*printf("You selected Deletion of Name... \n");

    printf("Enter the Name need to be deleted: ");
    fgets(del, sizeof(del), stdin);*/

    printf("You selected Deletion of Name... \n");

    printf("Enter the Name need to be deleted: ");
	scanf("%s", del);

    //printf("%s\n", del);
    printf("The name to be deleted is: %s \n", del);

    printf("The address of ptr before cond: %p \n", ptr);

    /*if (head == NULL)
	    {
		printf("List is Empty, Deletion is not Possible!!\n");
	    }
	else
	    {*/

		struct node *p;

        printf("The address of p before p = ptr: %p \n", p);

		ptr = head;
        p = ptr;

        printf("The address of ptr after else cond: %p \n", ptr);

        printf("The address of p after p = ptr cond: %p \n", p);

        int comp = strcmp (ptr -> name, del);
        printf("strcmp OP is: %d \n", comp);

		while (strcmp (ptr -> name, del) != 0)
		    {
			ptr = ptr -> next;

            printf("The address of ptr inside while cond: %p \n", ptr);
		    }

        printf("The address of p after while loop: %p \n", p);

        p -> next = ptr -> next;
		free (ptr);

        printf("The address of p after p -> next: %p \n", p);

        printf("The address of ptr after free: %p \n", ptr);
    }

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
VOID display (void);

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
		    while( ptr != NULL)
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
    void add(char name[20]);
    void delete(char del[20]);
    void display();

	char nm[20], del[20];
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
				add(nm);
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
				    delete(del);
                    }

                //printf("The list after deletion is: \n");
				display();
				break;
				}

            case 3:
                exit(0);

			default:
				printf("Invalid Entry!!\n");
                printf("\n");
                break;
            }
        }
    }