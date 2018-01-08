
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define max 500

typedef struct 
{
	char receiverID[max];
	char subject[max];
	char email[max];
        int min;
	int sec;
	int hr;
	

}msg;

typedef struct
{
	char user[max];
	char password[max];	
}ID;




typedef struct sentbox
{

        msg data;
        struct sentbox *rlink,*llink;



}sentbox;


typedef struct
{
	
	char name[max];
	char senderID[max];
	char subject[max];
	char email[max];
	int min;
	int hr;
	int sec;
	


}inboxmsg;

typedef struct inbox
{
	inboxmsg data;	
	struct inbox *rlink,*llink;

}inbox;
inbox hd[4];

typedef struct
{
	char username[100];
	sentbox *s;
	


}userID;



typedef struct
{

	userID x[100];


}account;
void updatetime(sentbox* temp)
{
	time_t rawtime;
	struct tm * timeinfo;
	int day,month,year,hour,min,sec;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	day = timeinfo->tm_mday; month = timeinfo->tm_mon; year = timeinfo->tm_year;
	hour = timeinfo->tm_hour; min = timeinfo->tm_min; sec = timeinfo->tm_sec;
	//t1->day=day;
	//t1->month=month+1;
	//t1->year=year+1990;
	temp->data.hr=hour;
	temp->data.min=min;
	temp->data.sec=sec;
	
}


/*
Function Name: insert_inbox_msg
Functionality: inserts a msg into inbox of Smail user
*/

inbox insert_inbox_msg(inbox *head,inbox *temp)
{
	    	
		temp->rlink=head->rlink;
		temp->llink=head;
		head->rlink->llink=temp;
		head->rlink=temp;
		return *head;
	
}


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
	
	for(j=0;j<4;j++)
	{
		if((strcmp(u[j].user,p)==0) && (strcmp(p,sender)!=0))
		{	
				flag=1;
				break;	
			

		}	
			
	}	
		for( k = 0; k != 4; ++k) {
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
	
			for(k=0;k<4;k++)
			{
				fscanf(filelist[k],"%s",check);
				if(strcmp(check,p)==0)
				{
					
				fprintf(filelist[k],"\nfrom :%s \t time:- %d:%d:%d\n %s",sender,first->data.hr,first->data.min,first->data.sec,r);
				}

			}	



		
			for(i=0;i<4;i++)
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

/*
Function Name: insert_sentbox_msg
Functionality: inserts a msg into sentbox of Smail user
*/


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


/* Function Name : delete_msg_sentbox
   functionality : deletes the msg from sentbox
*/


sentbox* delete_msg_sentbox(sentbox *head,int n)
{
			sentbox *temp,*i;
			int N=0;
			int ch;

			for(i=head,N=1;N<n-1;i=i->rlink,N++);
			temp=i->rlink;
			temp->rlink->llink=i;
			i->rlink=temp->rlink;

			printf("Deleted email from sentbox is the email from EmailID : %s\n\n",temp->data.receiverID);
			printf("ENTER THE CHOICE\n\n1)See the content of Email\n2)exit\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: printf("the content of Email is :\n");
					puts(temp->data.subject);
					printf("\n");
					printf("time:-\t %d:%d:%d\n",temp->data.hr,temp->data.min,temp->data.sec);
					puts(temp->data.email);
					printf("\n");
					
					
					free(temp);
					break;
	

				case 2: break;

			}

		        return head;
	

}

/* 
   Function Name : delete_msg_inbox
   functionality : deletes the msg from inbox
*/


inbox delete_inbox_msg(inbox *head,int n,char id[max])
{

	int ch,j;
	int N=0;
	inbox *i=NULL,*temp=NULL;
	for(j=0;j<4;j++)
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

/* Function Name: display_inbox
   functionality: display's the inbox list
*/

void display_inbox(inbox *head,char id[max])
{
	
	inbox *i;
	int n=1,ch,j;
	for(j=0;j<4;j++)
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


/* Function Name: display_sentbox
   functionality: display's the sentbox list
*/


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

/*  FUNCTIONALITY : searchs the email content in sentbox based on keyword inputed*/


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

/*  FUNCTIONALITY : searchs the email content in inboxbox based on keyword inputed*/

void  inbox_email_search(inbox *hd , char keyword[max],char id[max])
{
	
	int j;
	char *p;
	inbox *i;
	inbox A[max];
	int k=0;
	int n=0,ch,l=0;

	for(j=0;j<4;j++)
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

/*  FUNCTIONALITY : searchs the email content in inbox based on email id of sender inputed*/

void inbox_search_id(inbox *hd ,char searchID[max], char id[max])
{
	
	int j;
	char *p;
	inbox *i;
	inbox A[max];
	int k=0;
	int n=0,ch,l=0;

	for(j=0;j<4;j++)
	{

		if(strcmp(hd[j].data.name,id)==0)
		{
			for(i=hd[j].rlink;i!=&hd[j];i=i->rlink)
			{
				
				if(strcmp(hd[j].data.senderID,searchID)==0)
				{
					l++;					
					printf("%d) %s:-*received email content*\n",l,i->data.senderID); 
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


/*  FUNCTIONALITY : searchs the email content in sentbox based on email id of receivers inputed*/


void sentbox_search_id(sentbox *head , char searchID[max])
{
	char *p;
	int k=0;
	int m=0;
	int n,l=0,ch;
	sentbox *i=NULL;
	sentbox j[max];
	
	for(i=head->llink;i!=head;i=i->llink)
	{

		if(strcmp(i->data.receiverID,searchID)==0)
		{
			
					l++;					
					printf("%d) %s:-*sent content*\n ",l,i->data.receiverID); 
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


void get(FILE **filelist)
{

	int 	 i,flag=0,ch;
	char 	id[max];
	char     passkey[max];
	ID  	 u[max];
	FILE 	*p=NULL;
	FILE    *a=NULL;


	p=fopen("server.txt","r");
	a=fopen("password.txt","r");	

	for(i=0;i<4;i++)
	{
		fscanf(p,"%s",u[i].user);
		

	}

	fclose(p);

	for(i=0;i<4;i++)
	{

		fscanf(a,"%s",u[i].password);


	}	
	fclose(a);
	printf("\t\t ''WELCOME TO SMAIL.COM''\t\t\n");
	while(1)
	{

		printf("\nEnter the CHOICE \n1) SIGN IN\n2)EXIT\n\n");	
		scanf("%d",&ch);
		
		switch(ch)
		{

			case 1: printf(" Enter the userID : \n");
				scanf("%s",id);
				printf("Enter the password: \n");
				scanf("%s",passkey);
				for(i=0;i<4;i++)
				{
					if((strcmp(id,u[i].user)==0) && (strcmp(passkey,u[i].password)==0))
					{
						flag=1;
						break;


					}



				}

				if(flag==1)
				{

					login(id,u,filelist);
				}
				else
				{
					printf("The userID enter is not found in the server's account list (or) password is wrong\n SORRY ,TRY AGAIN :( \n");


				}
				break;

				case 2: printf("EXITING FROM SIGN IN PAGE \n \n");
					return ;


		}


	}

	
}

	
int main(int *argv , int **argc)
{
	int i,k;
	FILE *p=NULL;
	p=fopen("server.txt","r");
	for(i=0;i<4;i++)
	{
		fscanf(p,"%s",hd[i].data.name);
		strcpy(hd[i].data.senderID,"dummy");
		 strcpy(hd[i].data.subject,"dummy");
		 strcpy(hd[i].data.email,"dummy");
		 hd[i].llink=&hd[i];
		 hd[i].rlink=&hd[i];
	}


FILE **filelist = (FILE **) malloc(4 * sizeof(FILE*));
for( k = 0; k != 4; ++k) {
    char buf[1024];

    // now we build the file name
    strcpy(buf, "account"); // "domain"
    sprintf(buf+6,"%03d", k+1); // "domain001" ... "domain096")
    strcat(buf, ".txt"); // "domain001.txt" ... "domain096.txt"

    // open file
    filelist[k] = fopen(buf, "a+");
	fprintf(filelist[k],"%s",hd[k].data.name);
	fclose(filelist[k]);
	
}


	get(filelist);
	return 0;

}
