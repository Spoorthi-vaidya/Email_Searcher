#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"

void display_inbox(inbox *head,char id[max])
{
	
	inbox *i;
	int n=1,ch,j;
	for(j=0;j<214;j++)
	{    if(strcmp(id,head[j].data.name)==0)
		{
			if(head[j].rlink==&head[j])
			{
				printf("INBOX IS EMPTY \n\n ");
				return;
		
			}	

			printf("INBOX EMAIL LIST IS :\n");
			for(i=head[j].rlink,n=1;i!=&head[j];i=i->rlink,n++)
			{
					printf("%d) %s \n",n,i->data.senderID);
		
		

	
			}
			printf("Enter the choice\n 1) See the content of email 2)Exit\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: for(i=head[j].rlink,n=1;i!=&head[j];i=i->rlink,n++)
       				{
                		printf("%d) %s \n",n,i->data.senderID);
				printf("time:-\t %d:%d:%d\n",i->data.hr,i->data.min,i->data.sec);
				 printf("the content of Email is :\n");
                       		 puts(i->data.email);
                       		 printf("\n");
				}
				break;
				case 2: return;


			}

		}
	
	}
}


