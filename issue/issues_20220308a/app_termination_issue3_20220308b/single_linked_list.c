/*

Module: singly_linked_list.c

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
#include <conio.h>
#include <process.h>
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
TYPE name(
TYPE arg1, brief description of arg1
TYPE arg2 brief description of arg2);

Description:
    By getting names from user, we insert those names in the end of the list. If the list is empty, 
    we are inserting our new name in HEAD, if our list is not empty, we traverse through the list and after reaching the NULL, 
    we inserting our Name there and making the next node of new node as NULL.

Returns:
    Functions returning type void: Nothing.

*/

void add (char nm[])
    {
    /*printf("Enter the Name : ");
    scanf("%s",nm);*/

    struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp -> name[20] = nm[20];
    temp -> next = NULL;

    if (head == NULL)
	    {
		head = temp;
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
    To delete a given name on the list.

Definition:
TYPE name(
TYPE arg1, brief description of arg1
TYPE arg2 brief description of arg2);

Description:
    First Get names from user which has to be deleted, by using pointer, 
    we traverse through the list of elements and delete the exact Name which was typed by user. 
    After deletion, if it is HEAD node, we simply change next node as HEAD node, if its end node, 
    by using the pointer *p, we make the last previous node as last node and after the last node is NULL. 
    If the deletion is happening in between, the previous node and next node will join together leaving 
    the current node out of list. Now this current node can be deleted.

Returns:
    Functions returning type void: Nothing.

*/

void delete(char del[])
    {
    if (head == NULL)
	    {
		printf("List if Empty, Deletion is not Possible!");
	    }
	else
	    {
		struct node *p;

		ptr = head;
		while(ptr -> name != del)
		    {
			p = ptr;
			ptr = ptr -> next;
		    }

		p -> next = ptr -> next;
		free(ptr);
	    }
    }

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
TYPE name(
TYPE arg1, brief description of arg1
TYPE arg2 brief description of arg2);

Description:
    First it checks if the list is empty or not. If it is empty, then it prints "List is Empty" message.
    If the list contains elements, using pointer *ptr, 
    we traverse through all the elements one by one and print all elements.

Returns:
    Functions returning type void: Nothing.

*/

void display()
    {
        if (head == NULL)
	        {
		    printf("List is Empty");
	        }
	    else
	        {
		    ptr = head;
		    while( ptr != NULL)
		        {
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
                printf("You selected Insertion of Name... \n");

				printf("Now Enter the Name: ");
				scanf("%s", &nm[20]);

				add(nm[20]);
                printf("The list after addition is: \n");

				display();
				break;
                }

            case 2:
                {
                printf("You selected Deletion of Name... \n");

                printf("Enter the Name need to be deleted: ");
				scanf("%s", &del[20]);

				delete(del[20]);
                printf("The list after deletion is: \n");

				display();
				break;
				}

            case 3:
                exit(0);

			default:
				printf("Invalid Entry!!\n");
                printf("\n");
            }
        }
    }





























        /*struct symbtab *p;
        p=malloc(sizeof(struct symbtab));
        strcpy(p->label,l);
        printf("Enter the address : ");
        scanf("%d",&p->addr);
        p->next=null;*/
	
    
    
    /*strcpy
    temp->name=value;

	if (head== NULL)
	    {
		head=temp;
	    }
	else
	    {
		ptr=head;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=NULL;
	    }
    }*/


/*
int main()
    {
    char choice;

    void add();
    void delete();
    void display();

    while(1)
        {
        printf("a. Add Entry\nb. Delete Entry\nc. Display");

        printf("Enter your choice(a or b or c): ");
        scanf("%c", &choice);

        switch(choice)
            {
            case '1':
                add();
                break;
            case '2':
                delete();
                break;
            case '3':
                display();
                break;
            default:
                printf("Wrong Choice!\n");

            }
            return 0;
        }
    }

void add()
    {
    char person[50];

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter name: ");
    scanf("%d", &person[50]);

    temp -> name[50] = person[50];
    temp -> next = NULL;
 
    if(start == NULL)            //If list is empty
        {
        start = temp;
        }
    else
        {
        q = start;
        while(q -> next != NULL)
            {
            q = q -> next;
            q -> next = temp;
            }
        }
        
        return 0;
    }*/
