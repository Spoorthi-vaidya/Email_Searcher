#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


sentbox* insert_msg_sentbox(sentbox *head,inbox *hd,char sender[max],ID u[max],FILE **filelist)
{
	    	
		
		sentbox *temp=NULL;
		temp=getnode(temp,hd,sender,u,filelist);
		
		temp->llink=head->llink;
		temp->rlink=head;
		head->llink->rlink=temp;
		head->llink=temp;
		return head;
	



}

