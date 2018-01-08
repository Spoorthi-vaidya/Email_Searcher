#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


sentbox* getnode(sentbox *first,inbox *hd ,char sender[max],ID u[max],FILE **filelist)
{
	
	inbox *h;
	char check[max];
	int i=0,f=0,j=0,flag=0,k=0;

	char p[max],q[max],r[max];
	h=(inbox*)malloc(sizeof(inbox));
	first=(sentbox*)malloc(sizeof(sentbox));
	printf("Enter the Receiver's EmailID\n\n");
	scanf("%s",p);
	
	for(j=0;j<214;j++)
	{
		if((strcmp(u[j].user,p)==0) && (strcmp(p,sender)!=0))
		{	
				flag=1;
				break;	
			

		}	
			
	}	
		for( k = 0; k !=214; ++k) {
    char buf[1024];

    // now we build the file name
    strcpy(buf, "account"); // "domain"
    sprintf(buf+6,"%03d", k+1); // "domain001" ... "domain096")
    strcat(buf, ".txt"); // "domain001.txt" ... "domain096.txt"

    // open file
    filelist[k] = fopen(buf, "a+");
	
	
}	
		
	
		if(flag==1)	
		{	
			




			
			strcpy(first->data.receiverID,p);
			gets(q);		
			printf("Compose the Email:\n\n");
			gets(r);
			strcpy(first->data.email,r);
			updatetime(first);
	
			for(k=0;k<214;k++)
			{
				fscanf(filelist[k],"%s",check);
				if(strcmp(check,p)==0)
				{
					
				fprintf(filelist[k],"\nfrom :%s \t time:- %d:%d:%d\n %s",sender,first->data.hr,first->data.min,first->data.sec,r);
				}

			}	



		
			for(i=0;i<214;i++)
			{
				if(strcmp(first->data.receiverID,hd[i].data.name)==0)
				{	
								
					strcpy(h->data.senderID,sender);
					strcpy(h->data.email,r);
					h->data.min=first->data.min;
					h->data.hr=first->data.hr;
					h->data.sec=first->data.sec;
					h->rlink=NULL;
					h->llink=NULL;
					hd[i]=insert_inbox_msg(&hd[i],h);
					
			}
			}
			
			printf("\nEMAIL SUCCESSFULLY SENT , THANK YOU \n\n");
			first->llink=NULL;
			first->rlink=NULL;
			return first;
		}
		else
		{
				printf("The receiver's ID entered is not found in server's account list (OR) invalid Entered ID,\nSORRY TRY AGAIN\n\n"); 
	
				return first;
		}
	
	
	
}

