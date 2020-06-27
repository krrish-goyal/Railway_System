#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//For strcmp and other string functions
#include <ctype.h>			//For toupper and other character functions
void gotoxy(int x, int y) {             //gotoxy(x,y) puts the cursor at a desired location (x,y) on screen
    printf("%c[%d;%df", 0x1B, y, x);
}

int g=0;

struct trains
{
	char t_no[5];		//train number
	char source[25];
	char dept_time[4];	//departure time
	char destn[25];		//destination
	char arr_time[4]; 	//arrival time
	int seats_left;		//number of seats left
}train[43];

struct tickets
{
	int PNR;
	char t_no[5],psngr_name[40];
};

//************-enquiry() function-*************
int enquiry(char *sou,char *des)
{
	int i,flag=0;
	/*system("clear");
	gotoxy(28,1);
	printf("--------ENQUIRY--------");*/
	gotoxy(1,7);
	if (!(strcmp(sou,"DELHI")))
	{
		for(i=0;i<43;i++)
		{
			if(!(strcmp(des,train[i].destn)))
			{
				flag++;
				if ( flag==1)
				{
					printf("Train \tFrom  \tTo            \tDeparture\tArrival\tAvailability\n");
					printf("Number\t      \t              \tTime     \tTime\n");
					printf("---------------------------------------------------------------------\n");
				}
				fprintf(stdout,"%s \t%s \t%s",train[i].t_no,train[i].source,train[i].dept_time);
				fprintf(stdout,"%s     \t%s   \t\t%d\n",train[i].destn,train[i].arr_time,train[i].seats_left);
			}
		}
		if (flag==0)
			printf(">> No Train is available from %s to %s",sou,des);
		else
		{	printf(">> Do you want to book a train? (Y/n) : ");
			scanf("%c",&yn);
			if (yn=='y' || yn=='Y')
			{
				g=1;
				booking(sou,des);
			}
		 	else
				printf("Thank You!");	
		}
	}	
	else
		printf(">> No Train is available from %s",sou);
	return 0;
}

// *************-main() function-************
int main(){
	int choice,i;
	char s[80];
	char d[80];
	FILE *fp=fopen("train_list","r");
	for (i=0;i<43;i++)
	{
		fscanf(fp,"%s",train[i].t_no);
		fscanf(fp,"%s",train[i].source);
		fscanf(fp,"%s",train[i].dept_time);
		fscanf(fp,"%s",train[i].destn);
		fscanf(fp,"%s",train[i].arr_time);
		fscanf(fp,"%d",&train[i].seats_left);
	}
	fclose(fp);
	/*for(i=0;i<43;i++)
	{	
		printf("%s\t%s\t%s\t%s\t%s\t%d\n",train[i].t_no,train[i].source,train[i].dept_time,train[i].destn,train[i].arr_time,train[i].seats_left);
	}*/
	do{
		choice=0;
		system("clear");
		gotoxy(18,1);
		printf("---------RAILWAY RESERVATION SYSTEM---------");
		gotoxy(28,2);
		printf("_______________________\n");
		gotoxy(28,3);
		printf("|     1. Enquiry      |\n");
		gotoxy(28,4);
		printf("|_____________________|\n");	
		gotoxy(28,5);
		printf("|     2. Booking      |\n");
		gotoxy(28,6);
		printf("|_____________________|\n");
		gotoxy(28,7);
		printf("|   3. Cancellation   |\n");
		gotoxy(28,8);
		printf("|_____________________|\n");
		gotoxy(28,9);
		printf("|       4. Exit       |\n");
		gotoxy(28,10);
		printf("|_____________________|\n\n");
		gotoxy(1,11);
		printf("\n>> Enter your choice as 1/2/3/4\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				system("clear");
				gotoxy(28,1);
				printf("--------ENQUIRY--------");
				gotoxy(1,3);
				printf(">> Enter Source : ");
				fscanf(stdin,"%s",s);
				for (i=0;i<strlen(s);i++)
				{
					s[i]=toupper(s[i]);
				}
				printf("\n>> Enter Destination : ");
				fscanf(stdin,"%s",d);
				for (i=0;i<strlen(d);i++)
				{
					d[i]=toupper(d[i]);
				}
				enquiry(s,d);
				break;
			case 2:
				system("clear");
				gotoxy(28,1);
				printf("--------BOOKING--------");
				gotoxy(1,3);
				printf(">> Enter Source : ");
				fscanf(stdin,"%s",s);
				for (i=0;i<strlen(s);i++)
				{
					s[i]=toupper(s[i]);
				}
				printf("\n>> Enter Destination : ");
				fscanf(stdin,"%s",d);
				for (i=0;i<strlen(d);i++)
				{
					d[i]=toupper(d[i]);
				}
				booking(s,d);
				break;
			case 3:
				//cancellation();
				break;
			case 4:
				return 0;
			default:
				gotoxy(1,12);
				printf(">> PLEASE ENTER A VALID OPTION\n");
				printf(">> Enter any key to continue");
				getchar();
		}
	}while(!(choice==1 || choice==2 || choice==3 || choice==4));
	
	return 0;	
}







