#include <stdio.h>
#include <stdlib.h>
struct trains
{
	int t_no, seats_left, dept_time, arr_time;
	char source[25],destn[25];
}train[15];
struct passenger
{
	int PNR, t_no;
	char psngr_name[40];
};
int main(){
	int ch,i;
	FILE *fp=fopen("train_list","r");
	for (i=0;i<15;i++)
	{
		fscanf(fp,"%d",&train[i].t_no);
		fscanf(fp,"%s",train[i].source);
		fscanf(fp,"%d",&train[i].dept_time);
		fscanf(fp,"%s",train[i].destn);
		fscanf(fp,"%d",&train[i].arr_time);
		fscanf(fp,"%d",&train[i].seats_left);
	}
	/*for (i=0;i<15;i++)
	{
		printf("%d %s %d %s %d %d\n",train[i].t_no,train[i].source,train[i].dept_time,train[i].destn,train[i].arr_time,train[i].seats_left);
	}*/	
	do{
		ch=0;
		printf("___________________\n");
		printf("|   1. Enquiry    |\n");
		printf("|_________________|\n");	
		printf("|   2. Booking    |\n");
		printf("|_________________|\n");
		printf("| 3. Cancellation |\n");
		printf("|_________________|\n");
		printf("|     4. Exit     |\n");
		printf("|_________________|\n");
		printf("Enter your choice as 1/2/3/4\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				//enquiry();
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
				printf("PLEASE ENTER A VALID OPTION\n");
		}
	}while(!(ch==1 || ch==2 || ch==3 || ch==4));
	
	return 0;	
}







