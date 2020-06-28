#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//For strcmp and other string functions
#include <ctype.h>			//For toupper and other character functions
void gotoxy(int x, int y) {             //gotoxy(x,y) puts the cursor at a desired location (x,y) on screen
    printf("%c[%d;%df", 0x1B, y, x);
}

int booking(char *,char *);

int g=0;

struct trains
{
	char t_no[10];		//train number
	char source[25];
	char dept_time[10];	//departure time
	char destn[25];	//destination
	char arr_time[10]; 	//arrival time
	int seats_left;	//number of seats left
	int fare;
}train[43];

struct tickets
{
	int PNR; //JHJHGKJHCZCHZCZJCZLMV;ZLDMZ.DV.ZDN.ZDZN.KZN,KDZNC,KDZNV.ZK/DNVZJHVLkuHldYJGVkuVD,JCG<CUUGZD.KUVH
	char t_no[10];
	char psngr_name[40];
};
 struct tickets tix[43000];
 
//************-enquiry() function-*************
int enquiry(char *sou,char *des)
{
	int i,flag=0,yn;
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
				printf("%s \t%s \t%s          ",train[i].t_no,train[i].source,train[i].destn);
				printf("%s     \t%s   \t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left);
			}
		}
		if (flag==0)
			printf(">> No Train is available from %s to %s\n",sou,des);
		else
		{	printf(">> Do you want to book a train?");
			printf("\nenter (1 for yes/ 0 for no) : ");
			scanf("%d",&yn);
			if (yn==1)
			{
				g=1;
				printf("%d",g);
				booking(sou,des);
			}
		 	else
				printf("Thank You!\n");	
		}
	}	
	else
		printf(">> No Train is available from %s\n",sou);
	return 0;
}
int booking(char *sou,char *des)
{
	char tr_no[5];
	int i,j,flag=0,yn;
	if(g==1)
    	{
		gotoxy(28,14);
		printf("--------BOOKING--------");
		gotoxy(1,16);
		flag=1;
	}
	else
    	{
		gotoxy(1,7);
		if (!(strcmp(sou,"DELHI")))
		{
			for(i=0;i<15;i++)
			{
				if(!(strcmp(des,train[i].destn)))
				{
					flag++;
					if(flag==1)
					{
						printf("Train \tFrom  \tTo            \tDeparture\tArrival\tAvailability\tFare\n");
						printf("Number\t      \t              \tTime     \tTime\n");
						printf("-------------------------------------------------------------------------\n");
					}
					printf("%s \t%s \t%s          ",train[i].t_no,train[i].source,train[i].destn);
					printf("%s     \t%s   \t%d\t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left,train[i].fare);
				}
			}
		}
		else
			printf(">> No Train is available from %s",sou);
		if(flag==0)
			printf(">> No Train is available from %s to %s",sou,des);
		
	}
	if(flag!=0)
	{
		printf(">> Enter the train number of your preferred booking : ");
		scanf("%s", tr_no);
		for(i=0;i<43;i++)
		{
			if(strcmp(tr_no,train[i].t_no)==0)
			{
				system("clear");
				gotoxy(28,1);
				printf("--------BOOKING--------");
				gotoxy(27,3);
				printf("******Train Details******");
				gotoxy(1,5);
				printf("Train \tFrom  \tTo            \tDeparture\tArrival\tAvailability\tFare\n");
				printf("Number\t      \t              \tTime     \tTime\n");		
				printf("------------------------------------------------------------------------\n");
				printf("%s \t%s \t%s",train[i].t_no,train[i].source,train[i].destn);
				gotoxy(34,8);
				printf("%s     \t%s   \t%d        \t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left,train[i].fare);
				gotoxy(1,10);
				printf(">> CONFIRM BOOKING ?");
				printf("\n>> enter (1 for yes/ 0 for no) : ");
				scanf("%d",&yn);
				if(yn==1)
				{
					struct tickets p_details;
					printf(">> Enter your name : \n");
				    	fgets(p_details.psngr_name,40,stdin);
					scanf("%39[^\n]",p_details.psngr_name);
					
					FILE *fq=fopen("passenger_list.txt","r");
					for(j=0;j<43000,getc(fq)!=EOF;j++)
					{
						fscanf(fq,"%d\t%s\t%s",&tix[i].PNR,tix[i].psngr_name,tix[i].t_no);
					}
					/*for(j=0;i<43000,getc(fq)!=EOF;i++)
					{
						printf("%d\t%s\t%s\n",tix[i].PNR,tix[i].psngr_name,tix[i].t_no);
					}*/
					printf("%s",tix[1].t_no);
					fclose(fq);	
					strcpy(p_details.t_no,tr_no);
					
					FILE *fp=fopen("passenger_list.txt","a");
					fprintf(fp,"%d\t%s\t%s\n",p_details.PNR,p_details.psngr_name,p_details.t_no);
					//fwrite(&p_details,sizeof(p_details),1,fp);
					fclose(fp);
					printf("\n*******BOOKING CONFIRMED********\n");
					break;
					
				}
				
		   	}		
		}
				
	}
	return 0;
}

// *************-cancellation() function-************
/*int cancellation( int a_pnr,char *b_tno)
{	
	FILE *fq,*ft;
	fq=fopen("passenger_list","rb+");
	int i,j,flag=0,recsize;
	for (i=0;i<43000;i++) //this code fragment is for accessing a specific entry in the entire array of structures for ticket data
	{	
		
		if(tix[i].PNR == a_pnr)
		{
			recsize = sizeof(tix);
			fq = fopen("passenger_list_temp","wb");
			rewind(fq);
			while(fread(&tix,recsize,1,fq)==1)
			{
				if(tix[i].PNR!=a_pnr)
					fwrite(&tix,recsize,1,ft);
				
			}	
			fclose(fq);
			fclose(ft);
			remove("passenger_list");
			rename("passenger_list_temp","passenger_list");
			
			fq = fopen("passenger_list","rb+");
			
			//above this is the code for deleting a line from the records
			
			flag=1;
			for(j=i+1; j<43000;j++)
			{	
				tix[j-1]=tix[j];
				if(j==42999) 
				{
					tix[42999].t_no=NULL;
					tix[42999].psngr_name=NULL;
					tix[42999].PNR=0;
				     	break;
				}
			}
			
		}
	}
	if(flag==0)
	{
		printf(">> Invalid PNR entered.\n>> Try again.");
		return 0;
	}
	
	for (int k=0; k<43; k++)
	{	
		if(strcmp(train[k].t_no,b_tno)==0)
		{
			train[k].seats_left+=1;
			//INCLUDE A NEW VARIABLE FOR COST OF EACH AND EVERY TRAIN
			int cost= train[k].fare * 0.5;
			printf("Amount refunded after 50 percent cancellation charges is INR %d", cost);
		}	
	}
	return 0;

}*/

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
		fscanf(fp,"%d",&train[i].fare);
		//fscanf(fp,"%*[^\n]");
	}
	fclose(fp);
	/*for(i=0;i<43;i++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n",train[i].t_no,train[i].source,train[i].dept_time,train[i].destn,train[i].arr_time,train[i].seats_left,train[i].fare);
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
				/*int p;
				char t[11];
				system("clear");
				gotoxy(28,1);
				printf("------CANCELLATION------");
				gotoxy(1,3);
				printf(">> Enter PNR: ");
				scanf("%d",&p);
				printf(">> Enter Train Number of the booking to be cancelled : ");
				scanf("%s",t);
				cancellation(p,t);*/
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
	}while(!(choice==1 || choice==2 || choice==3 || choice==4));
	
	return 0;	
}








