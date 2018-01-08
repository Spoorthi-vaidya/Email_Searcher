#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


void  inbox_email_search(inbox *hd , char keyword[max],char id[max])
{
	
	int j;
	char *p;
	inbox *i;
	inbox A[max];
	int k=0;
	int n=0,ch,l=0;

	for(j=0;j<214;j++)
	{

		if(strcmp(hd[j].data.name,id)==0)
		{
			for(i=hd[j].rlink;i!=&hd[j];i=i->rlink)
			{
				p=strstr(i->data.email,keyword);
				if(p)
				{
					l++;					
					printf("%d) %s contains %s \n ",l,i->data.senderID,keyword); 
					A[k]=*i;
					k++;
					

				
				}		
	


			}

		}


	}

	while(1)
	{

		printf("Enter the choice\n1) See the content of required Email that has fit  the search querry\n2)exit\n\n ");
		scanf("%d",&ch);

		switch(ch)
		{
		   	case 1: printf("Enter the email number whose content you want to see:\n");
			scanf("%d",&n);
			printf(" %s : %s \n ",A[n-1].data.senderID,A[n-1].data.email);						
			break;
			case 2:return;	
		
		}





	}
	



}
