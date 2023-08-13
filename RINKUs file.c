
#include <stdio.h>
#include "conio2.h"
#include <string.h>
#include"rinkus header.h"

void addAdmin()

{
    FILE *fp = fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","test","Ravi"},{"super","demo","Anil"}};
        fwrite(u,sizeof(u),1,fp);
    }
    fclose(fp);
}
User * getinput()
{
    int i;
    clrscr();
    int result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1; i<80; i++)
        printf("%c",247);
        gotoxy(1,15);
    for(i=1; i<=80; i++)
        printf("%c",247);
     gotoxy(60,8);
     textcolor(WHITE);
     printf("Press 0 to exit");
      gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter userid:");
    textcolor(WHITE);
    static User u;
    fflush(stdin);
    fgets(u.userid,20,stdin) ;
    char *pos;
    pos = strchr(u.userid, '\n');
    if(pos!=NULL)
    {
                *pos = '\0';
    }
    if(strcmp(u.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
        textcolor(LIGHTCYAN);
        gotoxy(25,11);
        printf("Enter pasword:");
        fflush(stdin);
        i=0;
        textcolor(WHITE);
        for(  ;    ;   )
        {
           u.pwd[i]= getch();
           if(u.pwd[i]==13)
           {
               break;
           }
           printf("*");
           i++;
        }
         u.pwd[i]= '\0';
         if(strcmp( u.pwd,"0")==0)
       {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
       }

      getch() ;
      return &u;
}
int checkUserExist(User u, char *usertype)
{

     FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
        fp=fopen ("admin.bin","rb");
    }
    else
    {
        fp=fopen ("emp.bin","rb");
    }
    if(fp==NULL)
    {
         gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry cannot open the file");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t");
        return -1;
    }
    int found=0;
    User user;
    while (fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
         gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("invalid userid password try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t");
    }
    else
    {
         gotoxy(28,20);
        textcolor(GREEN);
        printf("Login successful");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t");
    }
    return 1;
    fclose (fp);
return found;
}

int adminMenu()
{
    int i;
    int choice;
    gotoxy(32,2);
    textcolor(RED);
  printf("CAR RANTEL SYSTEM");
    gotoxy(35,6);
    textcolor(GREEN);
    printf("ADMIN MENU");
    for(i=0;i<80;i++)
    {
        printf("*");

}
    gotoxy(32,8);
    textcolor(YELLOW);
  printf("1.ADD EMPIOYEE");
  gotoxy(32,9);
  printf("2.ADD CAR DETAILS");
  gotoxy(32,10);
  printf("3.SHOW EMPLOYEE");
  gotoxy(32,11);
  printf("4.show CAR DETAILS");
  gotoxy(32,12);
  printf("5.DELETE EMPLOYEE");
  gotoxy(32,13);
  printf("6.DELETE CAR DETAILS");
  gotoxy(32,14);
  printf("7.EXIST");
  gotoxy(32,15);
  printf("ENTER YOUR CHOICE:");
  textcolor(WHITE);
  scanf(" %d",&choice);

  return choice;
}
void addEmployee()
{
    clrscr();
    char temp[10];
    char *pos;
    char choice;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec= ftell(fp)/sizeof(User);  ////
//we use this logic when we


if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        printf("Temp is %s",temp);
        getch();
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);  // ascii to integer ....atoi("25");-----25
        printf("\n total rec is %d",total_rec);
        getch();
    }




     total_rec++;
    sprintf(u.userid,"EMP-%d", total_rec);
    fseek(fp,0,SEEK_END);
    //strcat(empid,temp);
    //strcpy(u.userid,empid);
     do
     {
         clrscr();
         gotoxy(32,2);
         textcolor(LIGHTRED);
         printf("CAR RENTAL APP");
          textcolor(LIGHTGREEN);
         int i;
         gotoxy(1,3);
         for(i=1; i<=80; i++)
            printf("~");
          textcolor(WHITE);
          gotoxy(25,5);
          printf("***** ADD EMPLOYEE DETAILS *****");
          gotoxy(1,8);
           textcolor(YELLOW);
           printf("Enter Employee Name:");
           fflush(stdin);
           textcolor(WHITE);
           fgets(u.name,20,stdin);
           char *pos;
           pos= strchr(u.name,'\n');
           if(pos!=NULL)
           {
               *pos='\0';
           }
            textcolor(YELLOW);
            printf("Enter Employee Pwd:");
           fflush(stdin);
           textcolor(WHITE);
           fgets(u.pwd,20,stdin);
            pos= strchr(u.pwd,'\n');
           if(pos!=NULL)
           {
               *pos='\0';
           }
            fwrite(&u,sizeof(u),1,fp);   // sara data aa gya ab file m likhege
            gotoxy(30,15);
            textcolor(LIGHTGREEN);
            printf("EMPLOYEE ADDED SUCCESSFULLY!");
            printf("\nEMPLOYEE ID is %s",u.userid);
          getch();
          gotoxy(1,20);
         textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE EMPLOYEE (Y/N)? :");
          textcolor(WHITE);
          fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
            break;
        total_rec++;    // jo 1 bana hua h ause 2 karde
        sprintf(u.userid,"EMP-%d",total_rec);  // ek naye id ready ho jayege
     }while(choice=='y'  || choice=='Y');
     fclose(fp);
}

 void addCarDetails()
 {
clrscr();
    FILE *fp;
    int carid=1;
    char temp[10];
    int choice;
    int i=0;
     Car Car;
    fp= fopen ("car.bin","ab+");
    if(fp==NULL)
    {
        printf("Sorry! cannot open the file");
        return 1;
    }
     do
     {
         clrscr();
    int i;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAT RENTAL APP");
    gotoxy(1,3);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("~");
   gotoxy(25,5);
   printf(" ADD CAR DETAILS ");
   carid++;
   gotoxy(1,6);
   textcolor(YELLOW);
   printf("1.Enter Car Model: ");
   fflush(stdin);
    textcolor(WHITE);
       fgets(Car.car_name,50,stdin);
    char *pos;
    pos=strchr(Car.car_name,'\n');
    if(pos!='\0')
    {
        *pos='\0';
    }

gotoxy(1,7);
   textcolor(YELLOW);
   printf("2.Enter car capacity: ");
    textcolor(WHITE);
   scanf("%d",&Car.capacity);
   gotoxy(1,8);
   textcolor(YELLOW);
   printf("3.Enter car count: ");
    textcolor(WHITE);
    scanf(" %d",&Car.car_count);
   gotoxy(1,9);
   textcolor(YELLOW);
   printf("4.Enter car price for per day: ");
    textcolor(WHITE);
    scanf(" %d",&Car.price);
     fwrite(&Car,sizeof(Car),1,fp);
     gotoxy(30,15);
       textcolor(LIGHTRED);
   printf("CAR ADDED SUCCESSFULLY");
   getch();
   gotoxy(1,20);
   textcolor(LIGHTGREEN);
    printf("DO YOU WANT TO ADD MORE CAR (Y/N)?:");
    textcolor(WHITE);
    fflush(stdin);
    scanf(" %c",&choice);
    if(choice=='N')
        break;
   } while(choice=='Y');
  fclose(fp);
 }
 void viewEmployee()
{
    clrscr();
FILE*fp=fopen("emp.bin","rb");
 User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\N");
    for(i=0;i<80;i++)
        printf("%c",247);
       gotoxy(31,5);
       textcolor(YELLOW);
        printf("EMPLOYEE DETAILS");
    gotoxy(1,7);
    textcolor(GREEN);
    for(i=0;i<=180;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("sorry !cannot open file");
        getch();

        return;

    }
    gotoxy(1,8);
    printf("Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",ur.userid);
        gotoxy(33,x);//row=x
        printf("%s",ur.name);
        gotoxy(57,x);
        printf("%s",ur.pwd);
        x++;


    }
    fclose(fp);
    getch();
}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTUM\n");
    for(i=1; i<=80; i++)
    {
        printf("%c",247);
    }
    gotoxy(29,5);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
     textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
    {
        printf("%c",247);
    }
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No employee added yet!");
        return -1;
    }
    FILE *fp2= fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
   if(fp2==NULL)
    {
        textcolor(LIGHTRED);

        printf("SORRY FILE CAN NOT BE OPEN");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter employee id to delet the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
            fwrite(&u,sizeof(u),1,fp2);
        else
           found=1;
    }
    fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
        remove("temp.bin");
     }
   else
     {
         result=remove("emp.bin");
         if(result!=0)
              return 2;
         result=rename("temp.bin","emp.bin");
         if(result!=0)
            return 2;
     }
    return found;
}
  void showCarDetail()
  {
    clrscr();
    int i,row;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");

    gotoxy(1,2);
    for(i=1;i<=80;i++)
        printf("%c",247);

    gotoxy(31,5);
    printf("* ALL CAR DETAILS *");

    textcolor(LIGHTGREEN);
    gotoxy(1,7);
    for(i=1;i<=80;i++)
        printf("%c",247);

    FILE * fp = fopen("car.bin","rb");
    if(fp == NULL){
        gotoxy(27,11);
        textcolor(LIGHTRED);
        printf("Sorry ! No Car added yet.");
        getch();
        return;
    }

    printf("CAR ID\t\tModel\t\tCapicity\tAvailable\tPrice/Day");

    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);


Car c;
    row = 10;
    fseek(fp,0,SEEK_SET);
    while(fread(&c,sizeof(c),1,fp)==1){
        gotoxy(1,row);
        printf("%d",c.car_id);
        gotoxy(17,row);
        printf("%s",c.car_name);
        gotoxy(33,row);
        printf("%d",c.capacity);
        gotoxy(49,row);
        printf("%d",c.car_count);
        gotoxy(65,row);
        printf("%d",c.price);
        row++;
    }
    fclose(fp);
    getch();
  }




int deleteCarModel()
{
    clrscr();
    FILE *fp1 = fopen("car.bin","rb");
    int i,result;
    int carid;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");

    // For Designing
    gotoxy(1,2);
    for(i = 1 ; i <= 80 ; i++)
        printf("%c",247);

    // For Desingning
    gotoxy(29,5);
    printf("* DELETE CAR MODEL *");

    // For Desingning
    textcolor(LIGHTGREEN);
    gotoxy(1,7);
    for(i = 1; i<= 80 ; i++)
        printf("%c",247);

    // For Desingning
    gotoxy(1,12);
    for( i = 1 ; i <= 80 ; i++)
        printf("%c",247);

    // check condition weather file is open / exist  or not
    if(fp1 == NULL){
        textcolor(LIGHTRED);
        gotoxy(32,9);
        printf("No Car Added Yet!");
        return -1;
    }

    // if file fp1 is successfully open then create a temp file
    FILE *fp2 = fopen("temp.bin","wb+");

    // take car id
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car Id to delete the record :");
    textcolor(WHITE);
    scanf("%d",&carid);
    Car c;

    // if car is found then set found = 1
    int found = 0;

    // loop for read all record from car.bin file
    while(fread(&c,sizeof(c),1,fp1) == 1){

        // this is condition to check carid is same or not
        if(carid != c.car_id)
        // if carid is not match then simply write car detail in temp
            fwrite(&c,sizeof(c),1,fp2);
        else
        // if carid is match then set found = 1 , to determine car is found or not
            found = 1;
    }
    // finally close both files
    fclose(fp1);
    fclose(fp2);

    // delete temp/car and rename
    if(found == 0)
        remove("temp.bin");
    else{
        result = remove("car.bin");
        if(result != 0 )
            return 2;
        result = rename("temp.bin","car.bin");
        if(result != 0)
            return 2;
    }
    return found;
}


int empMenu()
{
    // for desgning
    int choice ,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1; i<=80; i++ )
        printf("*");
     textcolor(YELLOW);
     gotoxy(32,8);
     printf("1. Rent a car");
      gotoxy(32,9);
      printf("2. Booking Details");
        gotoxy(32,10);
      printf("3. Available Car Details");
        gotoxy(32,11);
      printf("4. Show All Car Details");
        gotoxy(32,12);
      printf("5. Exit");
        gotoxy(32,15);
      printf("Enter choice:");
      scanf("%d",&choice);
      return choice;


}
int SelectCarModel()
{
    clrscr();
    FILE *fp=fopen("car.bin","rb");  //jis file se car ke detail nikalne hai.
    int flag ;
    int choice,rowno=9;
     Car C;    // ab jo file se record pade jayege wo kis taraf ke record hoge int, float ,char......yeh Car structure ke record hai
    gotoxy(34,rowno);
    // ab hume dekhana 1.innova wo dekhane ke liye file se record padhna padega
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        //ab ek resord read hokar hamare car var C m aagya
        if(C.car_count>0)
        {
            printf("%d. %s",C.car_id,C.car_name);
        gotoxy(34,++rowno);
        }
    }
    gotoxy(34,rowno+2);
    printf("Enter your choice:");
   while(1)   //while bcoz user agar galat choice de toh phir se  input le .
   {
       flag =0;
       scanf("%d",&choice);
       rewind(fp);
       while(fread(&C,sizeof(C),1,fp)==1)
     {
      if(C.car_count == choice  && C.car_count>0)// C.car id m sare id nhi hoge jb upr wala while loop rukega toh aus m sirf ek id hogw last wale
       {
          flag==1;
          break;
       }
    }
    if(flag==1)
    {
        fclose(fp);
    return flag;
    }
    else
    {
        gotoxy(37,rowno+4);
        textcolor(LIGHTRED);
        printf("Wrong input");
        getch();
        gotoxy(35,rowno+4);
        printf("\t\t\t");
        gotoxy(52,rowno+2);
        printf("\t\t\t\t\t");
        gotoxy(52,rowno+2);
        textcolor(WHITE);

    }
   }

}

        //get date current date bta rha
int isValidDate(struct tm dt)  // dt and  is argument // tm is structure ka nam hai

{
  if(dt.tm_year>=2021  && dt.tm_year<=2022) //if year ki value2021  2022 nhi hai to return 0;
       {
        // means false if nhi chlega
      if(dt.tm_mon>=1 && dt.tm_mon<=12)  //month check

      { //mday=month day                              //month ye sb 31 day ke hai,,
          if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==9 ||dt.tm_mon==10|| dt.tm_mon== 12))
       return 1;

      else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
         ///  LEAP YEAR = CONDTIONS->4 se  ho devide 100 n ho ya fir 400 se ho jaye
      return 1;
      else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
      return 1;
      else if( dt.tm_mday<=29 && dt.tm_mon==2  && (dt.tm_year%400==0 || (dt.tm_year%4==0) || (dt.tm_year%100!=0)))
          return 1;

          else    //1900%400==0    //1900%4==0          //1900%100equal nhi rhega 0 remainder
        return 0;
      }
       }
      else
    {
        return 0;
    }
  }





    void UpdateCarCount(int c)
    {
        FILE*fp=fopen("car.bin","rb+");
        if(fp==NULL)
        {
            printf("file is not open");
            getch();
            return 0;
        }

       Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)//read carega car ki
    {
        if(C.car_id==c)
        {
            int cc;
            int cc_new=C.car_count-1;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);
            getch();
        }
    }                                                                                                                                                                       //false
     fclose(fp);
}
void bookedCarDetail()
     {
         clrscr();
         FILE*fp=fopen("customer.bin","rb");
         Customer_Car_Details CC;
         int i;
         textcolor(YELLOW);
         gotoxy(32,1);
         printf("CAR RENTAL SYSTEM");
         for(i=0;i<=180;i++)
            printf("%c",247);
         gotoxy(31,5);
          textcolor(YELLOW);
          printf("BOOKED CAR DETAIL");
          gotoxy(1,7);
          textcolor(LIGHTGREEN);
          for(i=1;i<180;i++)
            printf("%c",247);
          gotoxy(1,8);
          printf("MODEL\t custname\t pick up\t Drop\t\s s_Date\t  EDate");
          gotoxy(1,9);
          textcolor(GREEN);
          for(i=0;i<180;i++)
            printf("%c",247);
          int x=10;
          textcolor(YELLOW);

          while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
          {
              gotoxy(1,x);
             // printf("%s",getCarName(CC.Car_id));
              gotoxy(13,x);
              printf("%s",CC.cust_name);
              gotoxy(27,x);
              printf("%s",CC.pickup);
              gotoxy(44,x);
              printf("%s",CC.drop);
              gotoxy(58,x);
              //printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
              gotoxy(70,x);
            // printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
              x++;
          }
           fclose(fp);
           getch();

     }
    char*getCarName(int car_id)
    {
        FILE*fp=fopen("car.bin","rb");
        static Car C;
        while(fread(&C,sizeof(C),1,fp)==1)
        {
             if(C.car_id==car_id)
            {
                break;
            }

    }
    fclose(fp);
    return C.car_name;
  }

void availableCarDetails()

{
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTEAL SYSTEM");
         textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(32,5);
         textcolor(YELLOW);
    printf("* AVAILABLE CAR DETAILS *");
      gotoxy(1,7);
      textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);

    if(fp==NULL)
    {
         gotoxy(32,8);
      textcolor(LIGHTRED);
        printf("Sorry! File cannot be opend!");
        getch();
        return 0;
    }
       gotoxy(1,8);
       printf("Car ID\t   Model\t\t\t   Capacity\tAvailable\tPrice/Day");
       gotoxy(1,9);
    for(i=1; i<=80; i++)
        printf("%c",247);
     int row=10;
     textcolor(YELLOW);
     while(fread(&C,sizeof(C),1,fp)==-1)
     {
         if(C.car_count>0)  //yeh hata dena showCarDetails
         {
                 gotoxy(2,row);
                 printf("%d",C.car_id);
                 gotoxy(12,row);
                 printf("%s",C.car_name);
                     gotoxy(35,row);
                     printf("%d",C.capacity);
                         gotoxy(50,row);
                         printf("%d",C.car_count);
                             gotoxy(68,row);
                             printf("%d",C.price);
                             row++;
         }
     }
     fclose(fp);
}





//car ko rent pe dega
int rentCar()
{
    Customer_Car_Details CC;  //car ko rent pe dene ke liye kis sructuer ke zarurat h
    int c,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
      textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1; i<=80; i++)
    {
         printf("*");
    }
     textcolor(YELLOW);
     gotoxy(32,8);


c=SelectCarModel();
      if(c==0 || c==-2)
      return c;
     CC.Car_id=c;
     clrscr();
textcolor(LIGHTGREEN);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
      textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1; i<=80; i++)
       {
            printf("*");
       }
   gotoxy(1,17);
    for(i=1; i<=80; i++)
       {
            printf("*");
       }
        textcolor(YELLOW);
        gotoxy(27,9);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    {
        *pos='\0';
    }
     textcolor(YELLOW);
    gotoxy(27,10);
     printf("Enter pickup point:");
     textcolor(WHITE);
     fflush(stdin);
    fgets(CC.pickup,30,stdin);
    pos=strchr(CC.pickup,'\n');
    {
        *pos='\0';
    }
     textcolor(YELLOW);
    gotoxy(27,11);
     printf("Enter drop point:");
     textcolor(WHITE);
     fflush(stdin);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    {
        *pos='\0';
    }
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter start date (dd/mm/yyyy/):");
    do
    {
        scanf("%d-%d-%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
       int datevalid = isValidDate(CC.sd);
        if(datevalid==0)  //  if(datevalid==1)
        {
            //break;
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date !");
         getch();
         gotoxy(27,18);
         printf("\t\t");
         gotoxy(56,12);
         printf("\t\t\t");
         gotoxy(56,12);
         textcolor(WHITE);
         }
         else
            break;
         }while(1);
         gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date (dd/mm/yyyy/):");
     textcolor(WHITE);
    do
    {
        scanf("%d-%d-%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        int datevalid = isValidDate(CC.ed);
          if(datevalid==0)
          {

            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date !");
         getch();
         gotoxy(27,18);
         printf("\t\t\t\t\t\t");
         gotoxy(54,13);
         printf("\t\t\t\t\t\t\t");
         gotoxy(54,13);
         textcolor(WHITE);
          }
          else
            break;
         }while(1);

         FILE *fp=fopen("Customer.bin","ab");
         if(fp==NULL)
         {
             gotoxy(27,18);
             textcolor(LIGHTRED);
             printf("Sorry ! File cannot be opened");
             getch();
                 gotoxy(27,18);
                 printf("\t\t\t");
             return -1;   //return 1 kyo main thode h
         }
         fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
         gotoxy(27,18);
         textcolor(WHITE);
         printf("Booking done for Car %d",CC.Car_id);
         printf("\nPress any key to continue");
         getch();
         fclose(fp);
         UpdateCarCount(c);

         return 1;
}

