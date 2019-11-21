#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define small 20
#define large 100

typedef struct student{                         //creating struct where we will copy our parameters
	char namef[small];
	char namel[small];
	int roll;
	int fees;
	char date[small];

}student;



void delete_by_name(char namef[large],char namel[large])       //function for deleting record by name//
{
	struct student s[large];
	FILE *db;
	db = fopen("db.txt","r");
	int i = 0;
	while(!feof(db))                                          //reading db.txt till end of file//
	{
		fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[i].namef,s[i].namel,&s[i].roll,&s[i].fees,s[i].date);
		i++;
	}
	FILE *db1;
	db1 = fopen("db.txt","w");                                //rewriting db.txt but without writing the record to be deleted//
	for(int j=0;j<i;j++)                                      
	{
		if((strcmp(s[j].namef,namef)==0) && (strcmp(s[j].namel,namel)==0))     //if name that has to be deleted matches with the name in file,it is not printed//
		{
			continue;
		}
		else                                                                   //else it is printed//
		{
			fprintf(db1,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[j].namef,s[j].namel,s[j].roll,s[j].fees,s[j].date);
		}
	}
}



void delete_by_roll(int roll)
{
	struct student s[large];
	FILE *db;
	db = fopen("db.txt","r");
	int i = 0;
	while(!feof(db))
	{
		fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[i].namef,s[i].namel,&s[i].roll,&s[i].fees,s[i].date);
		i++;
	}
	FILE *db1;
	db1 = fopen("db.txt","w");
	for(int j=0;j<i;j++)
	{
		if(s[j].roll==roll)
		{
			continue;
		}
		else
		{
			fprintf(db1,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[j].namef,s[j].namel,s[j].roll,s[j].fees,s[j].date);
		}
	}
}



