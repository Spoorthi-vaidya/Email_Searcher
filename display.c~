#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


void display (sentbox *head)
{
	sentbox *i;
	int n=1,ch;
	if(head->llink==head)
	{
		printf("SENT BOX IS EMPTY \n\n ");
		return;

	}	

	printf("SENTBOX list\n");
	for(i=head->llink,n=1;i!=head;i=i->llink,n++)
	{
		printf("%d) %s \n",n,i->data.receiverID);
		
		


	}
	printf("Enter the choice\n 1) See the content of email 2)Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: for(i=head->llink,n=1;i!=head;i=i->llink,n++)
       			{
                		printf("%d) %s \n",n,i->data.receiverID);
				printf("time:-\t %d:%d:%d\n",i->data.hr,i->data.min,i->data.sec);
				 printf("the content of Email is :\n");
                        	puts(i->data.subject);
                        	printf("\n");
                       		 puts(i->data.email);
                       		 printf("\n");
			}
			break;
		case 2: return;


	}



}

