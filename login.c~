#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


/* FUNCTIONALITY: logs the user into account successfully and provides the option for using smail service efficiently*/


void login(char id[max],ID u[max],FILE **filelist)
{
	printf("LOGGED IN SUCCESSFULLY \n\n");
	char s[max],m[max];
	int ch,n,i;
	inbox k;
	sentbox *head;
	char keyword[max];
	char searchID[max];
	

	head=(sentbox*)malloc(sizeof(sentbox));
	strcpy(head->data.receiverID,"dummy");
	 strcpy(head->data.subject,"dummy");
	 strcpy(head->data.email,"dummy");
	 head->llink=head;
	 head->rlink=head;
	
	while(1)
	{

		printf("MENU:\n");

		printf("Enter the choice\n\n1)Display Sentboxlist\n2)Compose Email\n3)Delete Sentbox Email\n4)Delete Inbox Email\n5)Display Inbox Email list\n6)Searching for required Email content in INBOX\n7)Searching for required email content in SENTBOX\n8)Searching for emails in SENTBOX based on Receiver's ID\n9)searching for the emails in INBOX based on sender ID\n10)LOG OUT\n\n");
		scanf("%d",&ch);


		switch(ch)
		{
			
			case 1:display(head);
				break;

			case 2: head=insert_msg_sentbox(head,hd,id,u,filelist);
				break;

			case 3: printf("Enter the Email Number which you want to delete:\n");
				scanf("%d",&n);
				head=delete_msg_sentbox(head,n);
				break;

			case 4:printf("Enter the Email Number Which you want to delete:\n ");
				scanf("%d",&n);
				 k=delete_inbox_msg(hd,n,id);
				break;

			case 5:display_inbox(hd,id);
				break;

			case 6:printf("Enter the KEYWORD for searching required email : \n");
				scanf("%s",keyword);				
				inbox_email_search(hd,keyword,id);
				break;

			case 7: printf("Enter the KEYWORD for searching required email : \n");
				scanf("%s",keyword);		
				sentbox_email_search(head,keyword);
				break;


			case 8:printf("Enter the Receiver's ID based on which searching of emails should be done:\n");
				scanf("%s",searchID);
				sentbox_search_id(head,searchID);
				break;

			case 9:printf("Enter the Sender's ID based on which searching of emails should be done:\n");
				scanf("%s",searchID);
				inbox_search_id(hd,searchID,id);
				break;

			case 10: printf("LOGGING OUT \n\n");
				return;


		}


	}



}


