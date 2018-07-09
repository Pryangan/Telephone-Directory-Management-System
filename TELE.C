#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>

//Function Declaration Part Start ********************
void choice();
void registration();
void login();
void main_menu();
void add_num();
void search_num();
void delete_num();
void modify_num();
void view_num();
void draw_line(int n,char ch);
//Function Declaration Part End **********************

//Function Defination Start *****
void draw_line(int n,char ch)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%c",ch);
 }
}

struct person{
 char name[20];
 char telno[11];
};

struct reg
{
 char name[20];
 char pass[20];
}w;
// Main Function*********
void main()
{
 int gd = DETECT, gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setbkcolor(BLUE);
 setcolor(GREEN);
// login();
// registration();
   choice();
 closegraph();
}

//****!!!!CHOICE!!!!****
void choice()
{
  int ch;
  cleardevice();
  settextstyle(4, HORIZ_DIR, 4);
  outtextxy(35, 10, "Telephone Directory Management System ");
  gotoxy(1,4);
  draw_line(80,'*');

  setcolor(BROWN);
  settextstyle(1, HORIZ_DIR, 1);
  outtextxy(10, 200, "1.Login                                         2.Registration");
  gotoxy(1,20);
  printf(" Enter Your Choice : ");
  fflush(stdin);
  scanf("%d",&ch);
  if(ch==1)
  {
   login();
  }
  else if(ch==2)
  {
   registration();
  }
  else
  {

  }
 closegraph();
}

//****!!!!REGISTRATION!!!!****
void registration()
{
 FILE *fp;
 char username[10],password[10],re_password[10],c,ch;int i;
 do
 {
  cleardevice();
  setcolor(GREEN);
  settextstyle(4, HORIZ_DIR, 4);
  outtextxy(35, 10, "Telephone Directory Management System ");
  gotoxy(1,4);
  draw_line(80,'*');

  printf("\n Enter Your Name : ");
  fflush(stdin);
  gets(username);
  fp=fopen("regis.txt","r");
  while(!feof(fp))
  {
   fscanf(fp,"%s",w.name,w.pass);
   if(strcmpi(w.name,username)==0)
   {
    printf("\n\n\n\t\t\tUsername Already Exist");
    getch();
    registration();
   }
   else
   {
    strcpy(w.name,username);
    break;
   }
  }
  fclose(fp);
  printf(" Enter Your Password : ");
  for(i=0;(c=getch())!=13;)
  {
    if(c!=8)
  {
   password[i]=c;
   printf("*");
    i++;
   }
   else
   {
    i--;
    if(i<0)
    {
     i++;
    }
    else
    {
     printf("\b");
    }
   }
  }
  password[i]='\0';
  printf("\n ReEnter Your Password : ");
  for(i=0;(c=getch())!=13;)
  {
    if(c!=8)
  {
  re_password[i]=c;
   printf("*");
    i++;
   }
   else
   {
    i--;
    if(i<0)
    {
     i++;
    }
    else
    {
     printf("\b");
    }
   }
  }
  re_password[i]='\0';
  if(strcmp(password,re_password)!=0)
  {
   setcolor(RED);
   settextstyle(1, HORIZ_DIR, 1);
   outtextxy(10, 130, "Password Not Matched..!! ");
   printf("\n\n\n Do You Want to Continue Again.....(Y)es or (N)o : ");
   fflush(stdin);
   scanf("%c",&ch);
  }
  else
  {
   setcolor(GREEN);
   settextstyle(1, HORIZ_DIR, 1);
   strcpy(w.pass,password);
   fp=fopen("regis.txt","a");
   fprintf(fp," %s %s",w.name,w.pass);
   fclose(fp);
   outtextxy(10, 130, "Registration Successful..!! ");
   getch();
   exit(0);
  }
 }while(ch=='y' || ch=='Y');
 getch();
 closegraph();
}

//****!!!!LOGIN!!!!****
void login()
{
 FILE *fp;
 char p[10],username[10],c,ch;int i,flag=0;;

do{
 cleardevice();
 setcolor(GREEN);
 settextstyle(4, HORIZ_DIR, 4);
 outtextxy(35, 10, "Telephone Directory Management System ");
 gotoxy(1,4);
 draw_line(80,'*');

 printf("\n Enter Your Name : ");
 fflush(stdin);
 gets(username);
 printf(" Enter Your Password : ");
 for(i=0;(c=getch())!=13;)
 {
   if(c!=8)
  {
   p[i]=c;
  printf("*");
   i++;
  }
  else
  {
   i--;
   if(i<0)
   {
    i++;
   }
   else
   {
    printf("\b");
   }
  }
 }
 p[i]='\0';
 fp=fopen("regis.txt","r");
 while(!feof(fp))
 {
  fscanf(fp," %s %s",w.name,w.pass);
 if(strcmp(username,w.name)==0 && strcmp(w.pass,p)==0)
  {
   flag=1;
  }
 }
  if(flag==1)
  {
   setcolor(GREEN);
   settextstyle(1, HORIZ_DIR, 1);
   outtextxy(10, 110, "Login Successfully..!! ");
    fclose(fp);
   getch();
  main_menu();
  }
  else
 {
   setcolor(RED);
   settextstyle(1, HORIZ_DIR, 1);
   outtextxy(10, 110, "Incorrect Password..!! ");
   getch();

 printf("\n\n\n	 Do You Want to Continue Again.....(Y)es or (N)o : ");
 fflush(stdin);
 scanf("%c",&ch);
 }
 }while(ch=='y' || ch=='Y');
  closegraph();
}

//****!!!!MAIN MENU!!!!****
void main_menu()
{
 char ch,ch1,m_menu;int menu,menu1;
 struct person obj;
 cleardevice();
 setcolor(GREEN);
 settextstyle(4, HORIZ_DIR, 4);
 outtextxy(35, 10, "Telephone Directory Management System ");

 do{
  gotoxy(1,4);
  draw_line(80,'*');
 printf("\n1.Add Record\n2.Search Record\n3.Delete Record\n4.Modify Record\n5.View Record\n6.Switch User\n7.Exit\nEnter Your Choice : ");
 scanf("%d",&menu);

 switch(menu)
 {
  case 1:

   add_num();
   break;
  case 2:

   search_num();
   break;
  case 3:
   delete_num();
   break;
  case 4:
   modify_num();
   break;
  case 5:
   view_num();
   break;
  case 6:
   gotoxy(1,4);
   draw_line(80,'*');
    printf("\nEnter Any key for Switch User....");
   main();
   getch();
   break;
  case 7:
   gotoxy(1,4);
   draw_line(80,'*');
  // Good Bye Message
   cleardevice();
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');

   printf("\nThank You And Welcome Again...");
   getch();
   exit(0);

   break;
  default:
   gotoxy(1,4);
   draw_line(80,'*');
   printf("\n\nYou Entered Wrong Choice....\n Do You Want to Continue Again (Y)es or N(o) : ");
   fflush(stdin);
   scanf("%c",&ch);
   break;
 }
 }while(ch=='Y' || ch=='y');
 closegraph();
}


// Add_num()
void add_num()
{
int menu1;
char ch1;
FILE *fp;
struct person obj;

 do{
   cleardevice();
   setcolor(GREEN);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');
   fp=fopen("data.txt","a");

   printf("\nEnter a Name : ");
   scanf("%s",&obj.name);
   printf("Enter Phone No. : ");
   scanf("%s",&obj.telno);

   if(strlen(obj.telno)!=10)
   {
    printf("Phone Number is less than ten Digit Or Phone Number is less than ten Digit...\n\n");
    getch();
    draw_line(80,'*');
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
   case 2:
    main_menu();
     break;
   }
   }
   else
   {
   printf("Name is %s and Phone Number is %s\n\n",obj.name,obj.telno);
   fprintf(fp," %s %s",obj.name,obj.telno);
   fclose(fp);
   draw_line(80,'*');
   fflush(stdin);
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
    case 2:
    main_menu();
     break;
   }
   }
   }while(ch1=='y' || ch1 == 'Y');
 closegraph();
}

// search_num()
void search_num()
{
 FILE *fp;
 struct person obj;
 int menu1,totrec=0;
 char ch1,name[20];

do
{
   cleardevice();
   setcolor(GREEN);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');
   fp=fopen("data.txt","r");
   printf("\t\t\t      Find Specific Record\n");
   draw_line(80,'-');
   printf("\nEnter Name : ");
   scanf("%s",name);
   while(!feof(fp))
   {
    fscanf(fp,"%s %s",obj.name,obj.telno);
    if(strcmpi(obj.name,name)==0){
     printf("\nName : %s",obj.name);
     printf("\nName : %s",obj.telno);
     totrec++;
    }
   }
   if(totrec==0)
   {
    printf("\nNo Data Found\n");
   }
   else
   {
    printf("\nTotal %d Record Modified\n",totrec);
   }
   fclose(fp);
   getch();
   draw_line(80,'*');
   fflush(stdin);
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
    case 2:
    main_menu();
     break;
   }
 }while(ch1=='y' || ch1 == 'Y');
closegraph();
}

// delete_num()
void delete_num()
{
 FILE *fp,*ft;
 struct person obj;
 int menu1;
 char ch1,name[20];

 do
 {
   cleardevice();
   setcolor(GREEN);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');

   gotoxy(1,4);
   draw_line(80,'*');
   printf("\n\nEnter Name to delete : ");
   scanf("%s",name);
   ft=fopen("temp.txt","wb");
   //printf("\n\nWe will do Delete operation later....\n");
   rewind(fp);
   while(fread(&obj,sizeof(obj),1,fp)==1)
   {
    if(strcmp(obj.name,name)!=0)
    {
     fwrite(&obj,sizeof(obj),1,ft);
    }
   }
   fclose(fp);
   fclose(ft);
   remove("data.txt");
   rename("temp.txt","data.txt");
   fp=fopen("data.txt","rb+");
   getch();
   draw_line(80,'*');
   fflush(stdin);
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
    case 2:
    main_menu();
     break;
   }
 }while(ch1=='y' || ch1 == 'Y');
closegraph();
}

// modify_num()
void modify_num()
{
 FILE *fp;
 struct person obj;
 int menu1,totrec=0;
 char ch1,name[20];

 do
 {
   cleardevice();
   setcolor(GREEN);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');

   gotoxy(1,4);
   draw_line(80,'*');
   fp=fopen("data.txt","r");
   printf("\t\t\t      Modify Specific Record\n");
   draw_line(80,'-');
   printf("\nEnter Name : ");
   scanf("%s",name);
   while(!feof(fp))
   {
    fscanf(fp,"%s %s",obj.name,obj.telno);
    if(strcmpi(obj.name,name)==0){
    fclose(fp);
    printf("Enter New Name :");
    scanf("%s",obj.name);
    printf("Enter New Number :");
    scanf("%s",obj.telno);
    fp=fopen("data.txt","r+");
    fwrite(&obj,sizeof(obj),1,fp);
    totrec++;
    }
   }
   if(totrec==0)
   {
    printf("\nNo Data Found\n");
   }
   else
   {
    printf("\nTotal %d Record Modified\n",totrec);
   }
   fclose(fp);

   getch();
   draw_line(80,'*');
   fflush(stdin);
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
    case 2:
    main_menu();
     break;
   }
 }while(ch1=='y' || ch1 == 'Y');
 closegraph();
}

// view_num()

void view_num()
{
int menu1;
FILE *fp;
struct person obj;
char ch1;

 do
 {
   cleardevice();
   setcolor(GREEN);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(35, 10, "Telephone Directory Management System ");
   gotoxy(1,4);
   draw_line(80,'*');

   gotoxy(1,4);
   draw_line(80,'*');
   fp=fopen("data.txt","r");
  printf("\n Name\t\t\t\t\t\t\t\tTelephone No.\n");
  draw_line(80,'-');
   while(!feof(fp))
   {
    fscanf(fp," %s %s",obj.name,obj.telno);
    printf(" %10s\t\t\t\t\t\t\t%s\n",obj.name,obj.telno);
   }
   fclose(fp);
   getch();
   draw_line(80,'*');
   fflush(stdin);
   printf("\n1.Do you want to Continue the Add phone no. operation\n2.Go to Main Menu\nEnter Your Choice : ");
   scanf("%d",&menu1);
   switch(menu1)
   {
    case 1:
     ch1='y';
     break;
    case 2:
    main_menu();
     break;
   }
 }while(ch1=='y' || ch1 == 'Y');
 closegraph();
}