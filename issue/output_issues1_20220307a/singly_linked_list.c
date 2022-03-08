/*

Module: Binary-Zeros-Ones-of-Decimal-Number.c

Function:
    Finding Binary zeros and Ones in a given decimal  number.

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

void add (char nm[20])
    {
    /*printf("Enter the Name : ");
    scanf("%s",nm);*/

    struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp -> name, nm;
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

void delete(char del[20])
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

void display()
    {
        if (head == NULL)
	        {
		    printf("List if Empty");
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

	printf("1. Add Entry \n");
	printf("2. Delete Entry \n");
	printf("3. Display Entries \n");
	printf("4. exit \n");

	while(1)
	    {
		printf("Enter the Choice \n");
		scanf("%d", &ch);

		switch(ch)
            {
            case 1:
				{
				printf("Enter the Name: ");
				scanf("%s", &nm);

				add(nm[20]);
				display();
				break;
                }

            case 2:
                {
                printf("Enter the Name need to be deleted: ");
				scanf("%s", &del);

				delete(del[20]);
				display();
				break;
				}

			case 3:
				exit(0);
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
