#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


void sentbox_email_search(sentbox *head , char keyword[max])
{

	char *p;
	int k=0;
	int m=0;
	int n,l=0,ch;
	sentbox *i=NULL;
	sentbox j[max];	
		
	for(i=head->llink;i!=head;i=i->llink)
	{
		p=strstr(i->data.email,keyword);
		if(p)
		{      
			l++;
			printf(" %d) %s contains %s \n",l,i->data.receiverID,keyword);
			j[k]=*i;
			k++;
	
			
		}



	}
	while(1)
	{	
		printf("Enter the choice\n1) See the content of required Email that has fit the search querry\n2)exit\n\n ");
		scanf("%d",&ch);

		switch(ch)
		{
		   	case 1: printf("Enter the email number whose content you want to see:\n");
			scanf("%d",&n);
			printf(" %s : %s \n ",j[n-1].data.receiverID,j[n-1].data.email);						
			break;
			case 2:return;	
		
		}
 	}		
}
