#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"






inbox delete_inbox_msg(inbox *head,int n,char id[max])
{

	int ch,j;
	int N=0;
	inbox *i=NULL,*temp=NULL;
	for(j=0;j<214;j++)
	{
		if(strcmp(head[j].data.name,id)==0)
		{
			for(i=head[j].rlink,N=1;N<n-1;i=i->rlink,N++);
			temp=i->rlink;
			temp->rlink->llink=i;
			i->rlink=temp->rlink;
			printf("The Deleting Email from Inbox :%s\n\n ",temp->data.senderID);
			printf("Enter The choice \n1)Want to see the content of email 2)exit\n\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:printf("the content of the Email is :\n"); 
					printf("time:-\t %d:%d:%d\n",temp->data.hr,temp->data.min,temp->data.sec);
					puts(temp->data.email);

					printf("\n");
					break;
				case 2: break;
			}
	
			free(temp);
		}	
	   return head[j];	
	}
	




}
