#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
int m_exit;
void delay(int);
void login();
void view_rec();
void create();
void account();
void withdraw();
void deposite();
void menu();
void main()
{
	char name[10],pass[6];
	int lo;
//	FILE *p=fopen("password.txt","a+");
	login:
		system("cls");
	printf("press 1 for login:\n");
	printf("press 2 for create account:\n");
	printf("press 3 for exit:\n");
	scanf("%d",&lo);
	system("cls");
	switch(lo)
	{
		case 1:
			login();
			break;
		case 2:
		    create();
		    goto login;
			break;	
		case 3:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
			break;
	    default:
	    	printf("you entered invalid choice!!\n");
	    	goto login;
	    	break;
	}
	
	
}
void login()
{
	system("cls");
	int a,i;
	char name1[10],name[10];
	char pass1[6],pass[6];
	FILE *p=fopen("password.txt","a+");
	pass:
	a=0;
	printf("enter your username:\n");
	fflush(stdin);
	gets(name1);
	printf("enter your password:\n");
	fflush(stdin);
    gets(pass1);
	while(fscanf(p,"%s%s",name,pass)!=EOF)
	{
		
		if(strcmp(pass1,pass)==0 && strcmp(name1,name)==0)
		{
			printf("\n\npassword match!\nloading");
			for(i=0;i<=6;i++)
			{
				delay(100000000);
				printf(".");
			}
			a++;
			menu();
			break;
		}
	//	printf("%s\t%d\n",name,pass);
	}
	fclose(p);
	if(a==0)
	{ 
	    system("cls");
		printf("you entered wrong password OR username!!!\n");
		printf("TRY AGAIN.....\n");
		goto pass;
	}
}
void create()
{
	system("cls");
	char name[10],pass[6];
	FILE *p=fopen("password.txt","a+");
	printf("enter your name:\n");
	fflush(stdin);
	gets(name);
	printf("create your 6 digit password:\n");
	fflush(stdin);
	gets(pass);
	fprintf(p,"%s\t%s\n",name,pass);
	printf("account created successfuly\n");
	fclose(p);
}
void menu()
{
	int ch;
	tryagain:
	system("cls");
	printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n");
	printf("\t\t\t\t\tMAIN MENU\n");
	printf("press 1 create new account:\n");
	printf("press 2 for deposite cash:\n");
	printf("press 3 for withdraw cash from account:\n");
	printf("press 4 for view transactions:\n");
//	printf("press 5 for search transaction:\n");
	printf("press 5 for exit:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		  account();
		break;
		case 2:
		  deposite();
		break;
		case 3:
		  withdraw();
		break;
		case 4:
		  view_rec();
		  break;
		case 5:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
		default:
		printf("you entered invalid choice!!\nTRY AGAIN...\n");
		goto tryagain;
		break;	
	}
}
void account()
{
	int i,b,c,amount,age,accno,accno1,amt;
	char name[10],date[10],ph[12];
	system("cls");
	FILE *pd=fopen("personal_details.txt","a+");
	FILE *t=fopen("transactions.txt","a+");
	FILE *tr=fopen("trans.txt","w");	
	printf("enter current date:\n");
	fflush(stdin);
	gets(date);
	printf("enter your name:\n");
	fflush(stdin);
	gets(name);
	printf("enter your phone number:\n");
	fflush(stdin);
	gets(ph);
	printf("enter your age:\n");
	fflush(stdin);
	scanf("%d",&age);
	ac_no:
	printf("create your 6 digit account number:\n");
	fflush(stdin);
	scanf("%d",&accno);
	printf("enter the amount to depsite:\n");
	scanf("%d",&amt);
	accno1=accno;
	fprintf(pd,"%s %s %s %d %d %d\n",date,name,ph,age,accno1,amt);
	fprintf(t,"%s\t%d\t%d\tCR\t%d\n",date,accno,amt,amt);
	fprintf(tr,"%d",amt);
	fclose(pd);
	fclose(t);
	fclose(tr);
	printf("\n\nACCOUNT CREATED SUCCESSFULLY...\n");
	ac_invalid:
	printf("\npress 1 for main menu:\n");
	printf("press 0 for exit:\n");
	scanf("%d",&m_exit);
	system("cls");
	switch(m_exit)
	{
		case 1:
			menu();
			break;
		case 0:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
			break;
		default:
			printf("you entered invalid choice!!\n");
			goto ac_invalid;
		
	}

}
void deposite()
{
	system("cls");
	int a,b;
	char date[10],date1[10],name[10],ph[10],tra[2]="CR";
	int age,acc,acc1,amt,amt1,amt2;
	FILE *pd=fopen("personal_details.txt","a+");
	FILE *tr=fopen("trans.txt","r");
	FILE *t=fopen("transactions.txt","a+");
    dep:
	printf("enter your account number:\n");
	scanf("%d",&acc);
	while(fscanf(pd,"%s %s %s %d %d %d\n",date,name,ph,&age,&acc1,&amt)!=EOF)
	{
		if(acc==acc1)
		{
			fscanf(tr,"%d",&amt2);
			fclose(tr);
			FILE *tr=fopen("trans.txt","w");
			printf("enter the current date:\n");
			fflush(stdin);
			gets(date1);
			printf("enter the amount to deposite:\n");
			scanf("%d",&amt1);
			amt2=amt2+amt1;
			fprintf(t,"%s\t%d\t%d\tCR\t%d\n",date1,acc,amt1,amt2);
			printf("deposite successful...\n");
			printf("YOUR ACCOUNT BALANCE IS %d\n",amt2);
			fprintf(tr,"%d",amt2);
			fclose(pd);
			fclose(tr);
			fclose(t);
			a++;
			break;
		}
	}
	if(a==0)
	{
		printf("you entered wrong account number!!!\n");
		dep2:
		printf("press 1 for main menu:\n");
		printf("press 0 for re-enter account number:\n");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
				goto dep;
				break;
			case 1:
				menu();
				break;
			default:
				printf("you enter invalid choice!!\nentre again...\n");
				goto dep2;
				break;
		}
	}
	dep3:
	printf("\npress 1 for main menu:\n");
	printf("press 0 for exit:\n");
	scanf("%d",&m_exit);
	switch(m_exit)
	{
		case 1:
			menu();
			break;
		case 0:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
			break;
		default:
			printf("you entered invalid choice!!\n");
			
			goto dep3;
			break;
    } 
	
}
void withdraw()
{
	system("cls");
	int a,b;
	char date[10],date1[10],name[10],ph[10],tra[2]="DR";
	int age,acc,acc1,amt,amt1,amt2;
	FILE *pd=fopen("personal_details.txt","a+");
	FILE *tr=fopen("trans.txt","r");
	FILE *t=fopen("transactions.txt","a+");
    dep:
	printf("enter your account number:\n");
	scanf("%d",&acc);
	while(fscanf(pd,"%s %s %s %d %d %d\n",date,name,ph,&age,&acc1,&amt)!=EOF)
	{
		if(acc==acc1)
		{
			fscanf(tr,"%d",&amt2);
			fclose(tr);
			FILE *tr=fopen("trans.txt","w");
			printf("enter the current date:\n");
			fflush(stdin);
			gets(date1);
			printf("enter the amount to withdraw:\n");
			scanf("%d",&amt1);
			amt2=amt2-amt1;
			fprintf(t,"%s\t%d\t%d\tDR\t%d\n",date1,acc,amt1,amt2);
			printf("withdrawn successful...\n");
			printf("YOUR ACCOUNT BALANCE IS %d\n",amt2);
			fprintf(tr,"%d",amt2);
			fclose(pd);
			fclose(t);
			fclose(tr);
			a++;
			break;
		}
	}
	if(a==0)
	{
		printf("you entered wrong account number!!!\n");
		dep2:
		printf("press 1 for main menu:\n");
		printf("press 0 for re-enter account number:\n");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
				goto dep;
				break;
			case 1:
				menu();
				break;
			default:
				printf("you enter invalid choice!!\nentre again...\n");
				goto dep2;
				break;
		}
	}
	dep3:
	printf("\npress 1 for main menu:\n");
	printf("press 0 for exit:\n");
	scanf("%d",&m_exit);
	switch(m_exit)
	{
		case 1:
			menu();
			break;
		case 0:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
			break;
		default:
			printf("you entered invalid choice!!\n");
			
			goto dep3;
			break;
    } 
}
void view_rec()
{
	system("cls");
	char date[10],tra[2];
	int acc,amt,amt1,acc1,a=0,b;
	FILE *t=fopen("transactions.txt","r");
	dep:
	printf("enter account number for transactions:\n");
	scanf("%d",&acc1);
	printf("Date\t\tAmount\tTransaction\tBalance\n");
	while(fscanf(t,"%s%d%d%s%d",date,&acc,&amt,tra,&amt1)!=EOF)
	{
		if(acc==acc1)
		{
			printf("%s\t%d\t%s\t\t%d\n",date,amt,tra,amt1);
			a++;
			
		}
	}
	fclose(t);
 if(a==0)
	{
		printf("you entered wrong account number!!!\n");
		dep2:
		printf("press 1 for main menu:\n");
		printf("press 0 for re-enter account number:\n");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
				goto dep;
				break;
			case 1:
				menu();
				break;
			default:
				printf("you enter invalid choice!!\nentre again...\n");
				system("cls");
				goto dep2;
				break;
		}
	}
	dep3:
	printf("\npress 1 for main menu:\n");
	printf("press 0 for exit:\n");
	scanf("%d",&m_exit);
	switch(m_exit)
	{
		case 1:
			menu();
			break;
		case 0:
			system("cls");
			printf("\n********THANK YOU FOR VISIT********\n");
			printf("press any key for exit...");
			getch();
			exit(0);
			break;
		default:
			printf("you entered invalid choice!!\n");
			system("cls");
			goto dep3;
			break;
    } 
}
void delay(int j)
{
	int i,k;
	for(i=0;i<j;i++)
	{
		k=1;
	}
}
