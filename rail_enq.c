#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

struct trains
{
	int t_no, seats_left;
	char source[25],destn[25],dept_time[4],arr_time[4];
}train[15];

struct passenger
{
	int PNR, t_no;
	char psngr_name[40];
};

int enquiry(char *sou,char *des)
{
	int i;
	system("clear");
	gotoxy(28,1);
	printf("--------ENQUIRY--------");
	gotoxy(1,3);
	if (!(strcmp(sou,"delhi")) || !(strcmp(sou,"Delhi")))
	{
		for(i=0;i<15;i++)
		{
			if(!(strcmp(des,train[i].destn)) || strcmp(des,train[i].destn)==32)
			{
				printf("Train \tSource\tDestination      \tDeparture\tArrival\t\tNumber of\n");
				printf("Number\t      \t                 \tTime     \tTime   \t\tSeats left\n");
				printf("---------------------------------------------------------------------\n");
				printf("%d \t%s \t%s",train[i].t_no,train[i].source,train[i].destn);
				gotoxy(35,6);
				printf("%s     \t%s   \t\t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left);
			}
		}
	}
	return 0;
}

int main(){
	int choice,i;
	char s[80];
	char d[80]="mumbai";
	FILE *fp=fopen("train_list","r");
	for (i=0;i<15;i++)
	{
		fscanf(fp,"%d",&train[i].t_no);
		fscanf(fp,"%s",train[i].source);
		fscanf(fp,"%s",train[i].dept_time);
		fscanf(fp,"%s",train[i].destn);
		fscanf(fp,"%s",train[i].arr_time);
		fscanf(fp,"%d",&train[i].seats_left);
	}
	//	printf("%d %s %d %s %d %d\n",train[i].t_no,train[i].source,train[i].dept_time,train[i].destn,train[i].arr_time,train[i].seats_left);
	do{
		choice=0;
		system("clear");
		gotoxy(28,1);
		printf("_______________________\n");
		gotoxy(28,2);
		printf("|     1. Enquiry      |\n");
		gotoxy(28,3);
		printf("|_____________________|\n");	
		gotoxy(28,4);
		printf("|     2. Booking      |\n");
		gotoxy(28,5);
		printf("|_____________________|\n");
		gotoxy(28,6);
		printf("|   3. Cancellation   |\n");
		gotoxy(28,7);
		printf("|_____________________|\n");
		gotoxy(28,8);
		printf("|       4. Exit       |\n");
		gotoxy(28,9);
		printf("|_____________________|\n\n");
		gotoxy(1,10);
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
				printf("\n>> Enter Destination : ");
				fscanf(stdin,"%s",d); 
				enquiry(s,d);
				break;
			case 2:
				//booking();
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







