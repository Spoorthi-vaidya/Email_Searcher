#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"


	
int main(int *argv , int **argc)
{
	int i,k;
	FILE *p=NULL;
	p=fopen("server.txt","r");
	for(i=0;i<214;i++)
	{
		fscanf(p,"%s",hd[i].data.name);
		strcpy(hd[i].data.senderID,"dummy");
		 strcpy(hd[i].data.subject,"dummy");
		 strcpy(hd[i].data.email,"dummy");
		 hd[i].llink=&hd[i];
		 hd[i].rlink=&hd[i];
	}


FILE **filelist = (FILE **) malloc(214* sizeof(FILE*));
for( k = 0; k != 214; ++k) {
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
