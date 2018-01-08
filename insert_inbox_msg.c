#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"

inbox insert_inbox_msg(inbox *head,inbox *temp)
{
	    	
		temp->rlink=head->rlink;
		temp->llink=head;
		head->rlink->llink=temp;
		head->rlink=temp;
		return *head;

	
}
