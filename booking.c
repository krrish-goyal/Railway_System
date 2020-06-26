int booking()
{
    if(globalcount=1)
    {
    int i,flag=0;
	system("clear");
	gotoxy(28,1);
	printf("--------BOOKING--------");
	gotoxy(1,3);
	if (!(strcmp(sou,"DELHI")))
	{
		for(i=0;i<15;i++)
		{
			if(!(strcmp(des,train[i].destn)))
			{
				flag=1;
				printf("Train \tFrom  \tTo            \tDeparture\tArrival\tAvailability\tFare\n");
				printf("Number\t      \t              \tTime     \tTime\n");
				printf("------------------------------------------------------------------------\n");
				printf("%s \t%s \t%s",train[i].t_no,train[i].source,train[i].destn);
				gotoxy(35,6);
				printf("%s     \t%s   \t\t%d\t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left,train[i].fare);
			}
		}
		if (flag==0)
			printf(">> No Train is available from %s to %s",sou,des);
	}
	else
		printf(">> No Train is available from %s",sou);
	int num;
	printf("Enter the train number of your preferred booking");
	scanf("%d", &num);
	printf("%s \t%s \t%s \t%s",train[num].t_no,train[num].source,train[num].destn);
				gotoxy(35,6);
				printf("%s     \t%s   \t\t%d\t%d\n",train[num].dept_time,train[num].arr_time,train[num].seats_left,train[num].fare);
				--ptr->train[num].seats;
    }
    else
    {
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
	gotoxy(1,3);
	if (!(strcmp(sou,"DELHI")))
	{
		for(i=0;i<15;i++)
		{
			if(!(strcmp(des,train[i].destn)))
			{
				flag=1;
				printf("Train \tFrom  \tTo            \tDeparture\tArrival\tAvailability\tFare\n");
				printf("Number\t      \t              \tTime     \tTime\n");
				printf("---------------------------------------------------------------------\n");
				printf("%s \t%s \t%s",train[i].t_no,train[i].source,train[i].destn);
				gotoxy(35,6);
				printf("%s     \t%s   \t\t%d\t%d\n",train[i].dept_time,train[i].arr_time,train[i].seats_left,train[i].fare);
			}
		}
		if (flag==0)
			printf(">> No Train is available from %s to %s",sou,des);
	}
	else
		printf(">> No Train is available from %s",sou);
	int num;
	printf("Enter the train number of your preferred booking");
	scanf("%d", &num);
	printf("%s \t%s \t%s \t%s",train[num].t_no,train[num].source,train[num].destn);
				gotoxy(35,6);
				printf("%s     \t%s   \t\t%d\t%d\n",train[num].dept_time,train[num].arr_time,train[num].seats_left,train[num].fare);
				--ptr->train[num].seats;
	}
	return 0;
}
