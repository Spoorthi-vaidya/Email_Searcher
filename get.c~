#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"




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

	for(i=0;i<214;i++)
	{
		fscanf(p,"%s",u[i].user);
		

	}

	fclose(p);

	for(i=0;i<214;i++)
	{

		fscanf(a,"%s",u[i].password);


	}	
	close(a);
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
				for(i=0;i<214;i++)
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

