#ifndef EMAIL_H
#define EMAIL_H

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
inbox hd[214];

typedef struct
{
	char username[100];
	sentbox *s;
	


}userID;



typedef struct
{

	userID x[100];


}account;



void updatetime(sentbox* temp);
inbox insert_inbox_msg(inbox *head,inbox *temp);
sentbox* getnode(sentbox *first,inbox *hd ,char sender[max],ID u[max],FILE **filelist);
sentbox* insert_msg_sentbox(sentbox *head,inbox *hd,char sender[max],ID u[max],FILE **filelist);
sentbox* delete_msg_sentbox(sentbox *head,int n);
inbox delete_inbox_msg(inbox *head,int n,char id[max]);
void display_inbox(inbox *head,char id[max]);
void display (sentbox *head);
void sentbox_email_search(sentbox *head , char keyword[max]);
void  inbox_email_search(inbox *hd , char keyword[max],char id[max]);
void inbox_search_id(inbox *hd ,char searchID[max], char id[max]);
void sentbox_search_id(sentbox *head , char searchID[max]);
void login(char id[max],ID u[max],FILE **filelist);
void get(FILE **filelist);


#endif

