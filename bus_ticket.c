#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130]={"Hanif Express","Unique","Shaymoli","London Express","Saintmartin Travels","Green Line"};

char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();
void name_number(int booking,char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();
int main()
{
   nav();

 return 0;
}

void nav() {
    system("cls");
 printf("Select any:\n");
    printf("1.User Login\n");
    printf("2.Registration \n");
    int log;
    scanf("%d", &log);
    if(log==1){
        login();
    }else if(log==2) {
        reg();
    }
}

void reg() {
 system("cls");
    printf("Enter your name: ");
    char name[20];
    fflush(stdin);
    scanf("%[^\n]", name);
    printf("Enter your password: ");

    char passwd[8];
    scanf("%s[^\n", passwd);
    FILE *fp;
    char full_path[25];
    sprintf(full_path, "./usr/%s", name);
    fp = fopen(full_path, "w");
    if(fp != NULL) {
        fputs(name, fp);
        fputs("\n", fp);
        fputs(passwd, fp);
        printf("Registration successfull!\n");
    }else{
        printf("erroer");
    }
    fclose(fp);
    getch();
    nav();
}

void menu() {
int num,i;
 do{
 system("cls");
 printf("\n\n\n");
 printf("======================================Transport Schedule & Journey Management System ======================================\n\n\n");
 printf("\t\t\t\t\t[1]=> View Bus List\n");
 printf("\n");
 printf("\t\t\t\t\t[2]=> Book Tickets\n");
 printf("\n");
 printf("\t\t\t\t\t[3]=> Cancle Booking\n");
 printf("\n");
 printf("\t\t\t\t\t[4]=> Bus Status Board\n");
 printf("\n");
 printf("\t\t\t\t\t[5]=> Exit\n\n");

printf("===============================================================================================================\n\n");
 printf("\t\t\tEnter Your Choice:: ");
 scanf("%d",&num);
 switch(num)
 {
 case 1:
 bus();
 break;
 case 2:
 booking();
 break;
 case 3:
 cancle();
 break;
 case 4:
 status();
 break;
 }
getch();
 }while(num != 5);
 system("CLS");
 printf("\t----------------------------------------------------------------------------------------------------------\n");
 printf("\t\t\t\t\tThank You For downloading this Appliction\t\t\t\t\t\t\n");
 printf("\t----------------------------------------------------------------------------------------------------------\n");
 printf("\t\t\t This project is developed by TEAM-4");

}

void bus()
{
 system("cls");
 printf("\n\n\n");
 printf("===========================================Transport Schedule & Journey Management System ============================================\n\n\n");
 printf("\t\t\t\t\t[1] => %s\n",ch[0]);
 printf("\n");
 printf("\t\t\t\t\t[2] => %s\n",ch[1]);
 printf("\n");
printf("\t\t\t\t\t[3] => %s\n",ch[2]);
 printf("\n");
printf("\t\t\t\t\t[4] => %s\n",ch[3]);
 printf("\n");
printf("\t\t\t\t\t[5] => %s\n",ch[4]);
}
void booking()
{
 int i=0;
 char numstr[100];
system("cls");
printf("===========================================Transport Schedule & Journey Management System ============================================\n\n\n");//for entering train number
bus();
printf("Enter the Bus number:--->");
scanf("%d",&trno);
system("cls");
printf("==============================Transport Schedule & Journey Management System ============================================\n\n\n");//for selecting coach
printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
FILE *f1, *fopen();
char str1[80]="32",str2[4],str3[4];
int seat1,seat2,booking=0;
if(trno == 1)
{
f1 = fopen("tr1.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}else if(trno == 2)
{
f1 = fopen("tr2.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}else if(trno == 3)
{
f1 = fopen("tr3.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(trno == 4)
{
f1 = fopen("tr4.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(trno == 5)
{
f1 = fopen("tr5.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
seat1=atoi(str1);
if(seat1 <= 0)
{
printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");
seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
if(trno == 1)
{
f1 = fopen("tr1.txt","w");
fputs(str1,f1);
fclose(f1);
}
else if(trno == 2)
{
f1 = fopen("tr2.txt","w");
fputs(str1,f1);
 fclose(f1);
}
else if(trno == 3)
{
f1 = fopen("tr3.txt","w");
fputs(str1,f1);
 fclose(f1);
}
else if(trno == 4)
{
f1 = fopen("tr4.txt","w");
fputs(str1,f1);
 fclose(f1);
}
else if(trno == 5)
{
f1 = fopen("tr5.txt","w");
fputs(str1,f1);
fclose(f1);
}
}
}
void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
 FILE *a,*b;
 int i=0;
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 a = fopen(tempstr1,"a");
 b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)
{
 printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
 printf("\t\t\t\tEnter the seat number:--->");
 scanf("%d",&number);
 printf("\t\t\t\tEnter the name of person:--->");
 scanf("%s",name[number-1]);

printf("\n======================================================================================================\n\n");
 printf("\n");
 itoa(number, tempstr, 10);
 fprintf(a,"%s ",name[number-1]);
 fprintf(b,"%s ",tempstr);
}
fclose(a);
fclose(b);
}
int read_number(int trno)
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");
 while(!feof(a))
 {
 number[i][j] = fgetc(a);
 if(number[i][j] == ' ')
 {
 j=0;
 i++;
 }
 else
 {
 j++;
 }
 }
 k=i;
 for(i=0; i<k; i++)
 {
 num1[i] = atoi(number[i]);
 }
 fclose(a);
 return k;
}
void read_name(int trno)
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");
 while(!feof(b))
 {
 name[i][j] = fgetc(b);
 if(name[i][j] == ' ')
 {
 j=0;
 i++;
 }
 else
 {
 j++;
 }
 }
 name[i][j]='\0';
 k=i;
 fclose(b);
}
void status()
{
system("cls");
printf("===========================================Transport Schedule & Journey Management System ============================================\n\n\n");
 int i,trno,index=0,j;
 printf("Enter the number of bus:---->");
 scanf("%d",&trno);
 j=read_number(trno);
 read_name(trno);

printf("____________________________________________________________________________________________________________________\n");
 printf(" Bus.no-->%d---->%s \n",trno,ch[trno-1]);

printf("____________________________________________________________________________________________________________________\n");
 char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "," Empty ","Empty ","Empty ","Empty "};
 for(i=0; i<j; i++)
 {
 strcpy(tempname[num1[i]],name[i]);
 }
 for(i=0; i<8; i++)
 {
 printf("\t\t\t\t");
 for(j=0; j<4; j++)
 {


    printf("%8d.%s\t",index+1,tempname[index+1]);

 index++;
 }
 printf("\n");
 }
}
void status_1(int trno)
{
 printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
 system("cls");
printf("===========================================Transport Schedule & Journey ManagementSystem ============================================\n\n\n");
 int i,index=0,j;
 j=read_number(trno);
 read_name(trno);
 char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
 for(i=0; i<j; i++)
 {
 strcpy(tempname[num1[i]],name[i]);
 }
 for(i=0; i<8; i++)
 {
 printf("\t\t\t\t");
 for(j=0; j<4; j++)
 {


    printf("%d. %s\t",index+1,tempname[index+1]);

 index++;
 }
 printf("\n");
}
}
void cancle()
{
int seat_no,i,j;
char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
printf("Enter the bus number:---->");
scanf("%d",&trno);
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
strcat(tempstr2,numstr);
read_number(trno);
read_name(trno);
status_1(trno);
printf("Enter the seat number:--->");
scanf("%d",&seat_no);
FILE *a,*b;
a = fopen(tempstr1,"w+");
b = fopen(tempstr2,"w+");
for(i=0; i<32; i++)
{
 if(num1[i] == seat_no)
 {
 for(j=0; j<32; j++)
 {
 if(num1[j] != seat_no && num1[j] != 0)
 {
 fprintf(b,"%d ",num1[j]);
 fprintf(a,"%s",name[j]);
 }
 else if(num1[j] == seat_no && num1[j] != 0)
 {
 strcpy(name[j],"Empty ");
 }
 }
 }
}
fclose(a);
fclose(b);
printf("\n\n");

printf("======================================================================================================\n");
printf("\t\t\t\tYour 200 taka has been Returned\t\t\t\n");

printf("======================================================================================================\n");
}
void admin()
{
 int ch;
 system("cls");
 printf("\n\n\t\t1.Admin login :\n");
 printf("\n\n\t\tEnter option:");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 login();
 break;
 }
}
void login()
{
int a=0,i=0;
 char uname[10],c=' ';
 char pword[10],code[10];
 char user[10];
 char pass[10];
 do {
system("cls");
 printf("\n ========================= SIGN IN ========================= ");
 printf(" \n ENTER USERNAME:-");
 fflush(stdin);
scanf("%[^\n]s", &uname);
printf(" \n ENTER PASSWORD:-");
scanf("%s", pword);

i=0;
FILE *fp;
char full_path[25];
sprintf(full_path, "./usr/%s", uname);
fp = fopen(full_path, "r");
char valid_name[20];
    char valid_pass[20];
if(fp!=NULL) {
    fgets(valid_name,20, fp);
    fgets(valid_pass,20, fp);

}

if(fp == NULL) {
    printf("FILE ERROR\n");
}else if(strcmp(pword,valid_pass) == 0)
{
    system("cls");
printf(" \n\n\n WELCOME TO OUR APPLICATION Transport Schedule & JourneyManagement System !!!! SIIGN IN IS SUCCESSFUL");

printf("\n\n\n\t\t\t\tPress any key to continue...");
getch();
menu();
break;
}
else
{
printf("\n error!!!! SIGN IN IS UNSUCESSFUL");
a++;
getch();
}
}
while(a<=2);
if (a>2)
{
printf("\nSorry you have entered the wrong username and password for four times!!!");
getch();
}
system("cls");
}
