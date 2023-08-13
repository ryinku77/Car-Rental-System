#include <stdio.h>
#include "conio2.h"
#include <string.h>
#include <time.h>
#include "car.h"

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
User * getlnput()
{
    int i;  // Loop lagane ke liye
    clrscr();   // screen pr likha aa jayega selet your choice 1 2 3
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);   // bcoz we want to printf ~~ in character form its ascii is 247
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1; i<=80; i++)
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
    static User u;    // Input lene ke liye variable
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
        return NULL;    // Login screen se back ho kar bapas main screen pr chale jayege.
    }
        textcolor(LIGHTCYAN);
        gotoxy(25,11);
        printf("Enter pasword:");
        fflush(stdin);
        i=0;
        textcolor(WHITE);
        for(  ;    ;   )    // pta nhi a kitna bada pasword hoga islye infinite chalaya hai. pr yeh pta h pasword dena band kb karega jb wo enter strike kareaga.
        {
           u.pwd[i]= getch();
           if(u.pwd[i]==13)     // enter ke ascii its a twist of getch() do key code chalte hai 10 = \r\n, 13= \n bez kuch func \n ko sirf \n mante hai.
           {
               break;
           }
               if(u.pwd[i]==8)
               {
                i--;
                printf("\b\b");
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
        return NULL;    // Login screen se back ho kar bapas main screen pr chale jayege.
       }
       // Jo bhi yaha se retun hoga ause receive karna padega  (dedination getlnput) kis m karna padega recive
      getch() ;
      return &u;
}
int checkUserExist(User u, char *usertype)
{
    if(strlen(u.userid)==0 || strlen(u.pwd)==0 )
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Both feild are mandatory. Try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t");
        return 0;
    }
     FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
        fp=fopen ("admin.bin","rb");
    }
    else
    {
        fp=fopen ("emp.bin","rb");
    }
    if(fp==NULL)  // yeh if islye bcoz ho sakta h ke jb yeh code pehle br run ho to admin ko admin ke file kholna chaye bcoz admon he to emply ko regster karega or ausse galte se 2 press ho jata h to emp ke file open ho jayage or abh emp register nhii hue h
    {
         gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry cannot open the file");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t");
        return -1;   // islye take bapas se hum ause main() pr chode de jagha choice mange jaa rhe the
    }
    int found=0;   // upr wala if nhi chla to file khule gye toh ab record search kare match kare toh 1 nhi toh 0
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
        printf("Invalid userid/Pasword. Try again");
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
    return found;
    fclose (fp);
}


int adminMenu()
{
    int i,choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENAL SYSTEM");
    textcolor(GREEN);
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=1; i<=80; i++)
        printf("*");
        textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee");
     gotoxy(32,9);
    printf("2. Add Car Details");
     gotoxy(32,10);
    printf("3. Show Employee");
     gotoxy(32,11);
    printf("4. Show Car Details");
     gotoxy(32,12);
    printf("5. Delete Employee ");
     gotoxy(32,13);
    printf("6. Delete Car Details");
     gotoxy(32,14);
    printf("7. Exit");
    gotoxy(32,16);
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}

void addEmployee()
{
    char empid[10]={"EMP-"};
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
        printf("Temp is %d",temp);
        getch();
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);  // ascii to integer ....atoi("25");-----25
        printf("\n total rec is %d",total_rec);
        getch();
    }

     total_rec++;
                                         // sprintf(temp,"%d", total_rec);
     sprintf(u.userid,"EMP-%d",total_rec);
     fseek(fp,60,SEEK_END);                             //  strcat(empid,temp);
                                         //   strcpy(u.userid,empid);
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


void viewEmployee()
{
    FILE *fp= fopen("emp.bin","rb");
    User ur;
    int i;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
     gotoxy(1,2);
    for(i=1; i<=80; i++)
        printf("%c",247);
      gotoxy(31,5);
      printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
      textcolor(LIGHTGREEN);
       for(i=1; i<=80; i++)
        printf("%c",247);
      if(fp==NULL)
      {
          gotoxy(31,9);
          textcolor(LIGHTRED);
          printf("Sorry! No employee added yet!");
          getch();
          return 0; // fclose(fp) islye nhi lagaya bcoz file open he nhi hue toh close kaise hoge.
      }
       gotoxy(1,8);
       printf("Employee ID\t\t\tName\t\t\tPasword");
       gotoxy(1,9);
        for(i=1; i<=80; i++)
        printf("%c",247);
        int row=10 ; // 2 logic h gotoxy lagyege toh 1 1 1 se increment karna padega yah \n bh use kar sakte hai
       textcolor(YELLOW);
      while(fread(&ur,sizeof(ur),1,fp)==1)
      {
          gotoxy(2,row);
          printf("%s",ur.userid);
          gotoxy(33,row);
          printf("%s",ur.name);
          gotoxy(57,row);
          printf("%s",ur.pwd);
          row++;
      }
      fclose(fp);
      getch();
}








void addCarDetails()
{
    FILE *fp;
    static int id,no;
    char temp[10];
    int choice;
    int i=0;
     Car c;
    fp= fopen ("car.bin","ab+");
    if(fp==NULL)
    {
        printf("Sorry! cannot open the file");
        return 1;
    }
     //fseek(fp,60,SEEK_END);
   //  c.car_id=ftell(fp)/sizeof(Car);
     //c.car_id++;
     fseek(fp,-(sizeof(c)),SEEK_END);
     no=fread(&id,sizeof(id),1,fp);
     if(no!=1)
     {
         id=1;
     }
     else{
        id++;
     }
fseek(fp,0,SEEK_END);
c.car_id=id;
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
   printf("***** ADD CAR DETAILS *****");
   gotoxy(1,6);
   textcolor(YELLOW);
   printf("1.Enter Car Model: ");
   fflush(stdin);
    textcolor(WHITE);
    gotoxy(19,6);
       fgets(c.car_name,50,stdin);
    char *pos;
    pos=strchr(c.car_name,'\n');
    if(pos!='\0')
    {
        *pos='\0';
    }
   gotoxy(1,7);
   textcolor(YELLOW);
   printf("2.Enter car capacity: ");
    textcolor(WHITE);
     gotoxy(22,7);
   scanf("%d",&c.capacity);
   gotoxy(1,8);
   textcolor(YELLOW);
   printf("3.Enter car count: ");
    textcolor(WHITE);
    gotoxy(19,8);
    scanf(" %d",&c.car_count);
   gotoxy(1,9);
   textcolor(YELLOW);
   printf("4.Enter car price for per day:");
    textcolor(WHITE);
       gotoxy(31,9);
    scanf("%d",&c.price);
     fwrite(&c,sizeof(c),1,fp);
     gotoxy(30,15);
       textcolor(LIGHTRED);
   printf("CAR ADDED SUCCESSFULLY");
   getch();
      gotoxy(2,16);        /////
    textcolor(LIGHTGREEN);
    printf("CAR ID IS:");
      gotoxy(40,16);
      printf("%d",c.car_id);
   gotoxy(3,20);
  textcolor(LIGHTGREEN);
    printf("DO YOU WANT TO ADD MORE CAR (Y/N)?:");
    textcolor(WHITE);
    fflush(stdin);
    scanf(" %c",&choice);
    if(choice=='N')
        break;
        id++;
   } while(choice=='Y' || choice=='y');
  fclose(fp);
}



int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];   //wo id jise delet karna hai
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
    if(fp1==NULL)  // agr admin ne koi emp add he nhi kara
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No employee added yet!");   // nhi kiye to yaha se bapas nikla jaye to retun -1
        return -1;
    }
    FILE *fp2= fopen("temp.bin","wb+");
   if(fp2==NULL)  // agr admin ne koi emp add he nhi kara
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry! cannot open temp file");
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
         result=remove("emp.bin");  // agar successfully remove fo gaye toh result m 0 ayega
         if(result!=0)
              return 2;
         result=rename("temp.bin","emp.bin");
         if(result!=0)
            return 2;
     }
    return found;                                            // total return hoga -1,-2,0,1.......0= record nhi mila....1=mila or del ho gya.....2= mtl remove yah rename m kuch probl hue h
}



void showCarDetails()
{
    FILE *fp= fopen("car.bin","rb");
    Car ur;
    int i;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
     gotoxy(1,2);
    for(i=1; i<=80; i++)
        printf("%c",247);
      gotoxy(31,5);
      printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
      textcolor(LIGHTGREEN);
       for(i=1; i<=80; i++)
        printf("%c",247);
      if(fp==NULL)
      {
          gotoxy(31,9);
          textcolor(LIGHTRED);
          printf("Sorry! No car added yet!");
          getch();
          return 0; // fclose(fp) islye nhi lagaya bcoz file open he nhi hue toh close kaise hoge.
      }
       gotoxy(1,8);
       printf("CAR ID\t\tMODEL\t\tAVILABLE\t\tPRICE/DAY");
       gotoxy(1,9);
        for(i=1; i<=80; i++)
        printf("%c",247);
        int row=10 ; // 2 logic h gotoxy lagyege toh 1 1 1 se increment karna padega yah \n bh use kar sakte hai
       textcolor(YELLOW);
      while(fread(&ur,sizeof(ur),1,fp)==1)
      {
           gotoxy(1,row);
          printf("%d",ur.car_id);
          gotoxy(16,row);
          printf("%s",ur.car_name);
          gotoxy(35,row);
          printf("%d",ur.capacity);
          gotoxy(59,row);
          printf("%d",ur.price);
          row++;
      }
      fclose(fp);
getch()  ;
}





// your code
/*
int deleteCarModel()
{
   FILE *fp1=fopen("car.bin","rb");
     int carid;//wo id jise delet karna hai
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTUM\n");
    for(i=1; i<=80; i++)
    {
        printf("%c",247);
    }
    gotoxy(29,5);
    printf("* DELETE CAR RECORD *");
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
    if(fp1==NULL)  // agr admin ne koi emp add he nhi kara
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No car added yet!");   // nhi kiye to yaha se bapas nikla jaye to retun -1
        return -1;
    }
    FILE *fp2= fopen("temp.bin","wb+");
    if(fp2==NULL)  // agr admin ne koi emp add he nhi kara
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry! cannot open temp file");
        return -1;
    }

    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter car id to delet the record:");
    textcolor(WHITE);
    scanf("%d",carid);
   Car c;
    int found=0;
    while(fread(&c,sizeof(c),1,fp1)==1)
    {
        if(carid!=c.car_id)
            fwrite(&c,sizeof(c),1,fp2);
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
         result=remove("car.bin");  // agar successfully remove fo gaye toh result m 0 ayega
         if(result!=0)
              return 2;
         result=rename("temp.bin","car.bin");
         if(result!=0)
            return 2;
     }
    return found;                                            // total return hoga -1,-2,0,1.......0= record nhi mila....1=mila or del ho gya.....2= mtl remove yah rename m kuch probl hue h
}*/


int deleteCarModel()
{
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
    FILE *fp=fopen("car.bin","rb");  //jis file se car ke detail nikalne hai.
    int flag;
    int choice,rowno=9;
     Car C;    // ab jo file se record pade jayege wo kis taraf ke record hoge int, float ,char......yeh Car structure ke record hai
    gotoxy(34,rowno);
    // ab hume dekhana 1.innova wo dekhane ke liye file se record padhna padega
     int carcount=0;                                   // final improve
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        //ab ek resord read hokar hamare car var C m aagya
        if(C.car_count>0)   // final improve:-Q- kya aisa ho sakta ke sare car book ho gye ho
        {
            printf("%d. %s",C.car_id,C.car_name);
            gotoxy(34,++rowno);
            ++carcount;      // final improve :- isse yeah pta chal jayega ke user ko kitnr car mile h show krne ke liye
        }
    }
    if( carcount==0)
      {
          fclose(fp);
             return -2;  // final improve
      }

    gotoxy(34,rowno+2);
    printf("Enter your choice (0 to quit):");   // final improve:-Q-kya aisa ho sakta h ke user ko in m se koi car pasand na aaye
   while(1)   //while bcoz user agar galat choice de toh phir se  input le .
   {
      flag =0;
       scanf("%d",&choice);
      if(choice==0)                                    //final improve
       {
           fclose(fp);
           return choice;
       }
       rewind(fp);
       while(fread(&C,sizeof(C),1,fp)==1)
     {
      if(C.car_id == choice && C.car_count>0)// C.car id m sare id nhi hoge jb upr wala while loop rukega toh aus m sirf ek id hogw last wale
       {
          flag=1;
          break;
       }
     }
       if(flag==1)
       {
          fclose(fp);
          return choice;
       }
  else
   {
        gotoxy(35,rowno+4);
        textcolor(LIGHTRED);
        printf("Wrong input");
        getch();
        gotoxy(35,rowno+4);
        printf("\t\t\t");
        gotoxy(64,rowno+2);
        printf("\t\t\t\t\t");
        gotoxy(64,rowno+2);
        textcolor(WHITE);

   }
   }
}

int isValidDate(struct tm dt)  //tm :-predefine structure
{
    int dd,mm,yy;
    time_t obj=time(0);
    struct tm *p=localtime(&obj);
    p->tm_year=1900+p->tm_year;
    p->tm_mon=1+p->tm_mon;

    dd=dt.tm_mday;
    mm=dt.tm_mon;
    yy=dt.tm_year;
  /* if(yy>=p->tm_year && yy<=p->tm_year+1)
    {
        if(mm>=1  && mm<=12)
        {
            if(dd>=1 && dd<=31)
            {
                if (mm==1 || mm==3 || mm==5 ||mm==7 ||mm==8||mm==10||mm==12)
                return 1;
                else if((dd >=1 && dd<=30)  && (mm==4 || mm==6 || mm==9 ||mm==11))
                return 1;
                else if((dd>=1 && dd<=28) && mm==2)
                return 1;
                else if((dd>=1 && dd<=29) && mm==2 && (yy%400==0 || (yy%4==0 && yy%100!=0))) //getdate (date)se aaj ke date mil jayege or aus se aaj ka year bhi mil jayega aus year se 2 saal aaage tk ka
                 return 1;
            }
               else
                    return 0;
            }
            else
                return 0;
        }
    if(yy>p->tm_year)
        return 1;
    else
    {
        if(mm>p->tm_mon)
        return 1;
    else if(mm== p->tm_mon && dd>=p->tm_mday)
        return 1;
    }
    return 0;
}*/
if(yy>=p->tm_year && yy<=p->tm_year+1)
{
    //Checking For Month
    if(mm>=1 && mm<=12)
    {
        //Checking For Days
        if(dd>0 && dd<=31)
        {
            if( (mm==4 || mm==6 || mm==9 || mm==11) && dd>30)
            {
                return 0;
            }
            else if(mm==2)
            {
                if( yy%4!=0  && dd>28 )
                      return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}
else
{
    return 0;
}

///Checking date Logically

    if(yy > p->tm_year)
        return 1;
    else
    {
        if( mm > p->tm_mon)
            return 1;
        else if( mm == p->tm_mon && dd >= p->tm_mday)
            return 1;
    }

    return 0;
}




void updateCarCount(int c_id) //car ke id jise rent pr diya gya h
{
    FILE *fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry! File cannot opend!");
        getch();
        return ;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {

        if(C.car_id==c_id)
        {

          int x=C.car_count;
           x--;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&x,sizeof(int),1,fp);

          //  fseek(fp,-4,SEEK_CUR);// ab file pointer ko aage bhejna hoga ek br m ek he id updat hoge toh bum break bhi kar sakte hai.
          break;
        }
    }
    fclose(fp);
}


void bookedCarDetails() //wo sare car ke detail jo booked ho chuke hai.
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    // if this file is open toh hume file se ek ek record nikalna h or screen pr show krna h
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(31,5);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
          printf("%c",247);
    gotoxy(1,8);
    printf("Model\t    Cust Name\t   Pick Up\t   Drop\t\t  S_Date\tE_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
          printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",getCarName(CC.car_id));  // twist Customer_Car_Details CC is structure m car ka naam nhi h car_id h toh id se naam kase milega ek function banana padega wo car_id lega or wo hume is car_id ka naam return karega

        gotoxy(13,row);
        printf("%s",CC.cust_name);

           gotoxy(27,row);
        printf("%s",CC.pickup);

           gotoxy(44,row);
        printf("%s",CC.drop);

        gotoxy(58,row);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year); //currrent date sd ke andar store h .....nested structure

        gotoxy(70,row);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);

        row++;
    }
    fclose(fp);
    getch();
}

char* getCarName(int car_id)
{
    FILE *fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! File cannot be opened");
        return NULL;
    }
    static Car C; // kise function se jb address return kare toh hume aus variable ko static krna chaheye
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==car_id)
        {

         break;
        }
    }
    fclose (fp);
    return C.car_name;

}
int rentCar( )  //car ke booking karega
{
    clrscr();
    Customer_Car_Details CC;  //car ke bookiing karane ke liye kis sructuer ke zarurat h
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

     c=SelectCarModel();  //screen pr jo car ke detal h wo ise structure se aa rhe h toh iise call karege
      if(c==0 || c==-2)                                    //final improve
      return c;
      CC.car_id=c;
     clrscr(); // SelectCarModel(); apna ui return karega isliiye screen clear kare

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
    fgets(CC.cust_name,30,stdin);  //keyboard se input le rahe h jo ke CC.cust_name m store kr rhe h
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
        scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        int datevalid = isValidDate(CC.sd);
        if(datevalid!=1)  //  if(datevalid==1)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date !");
         getch();
         gotoxy(27,18);
         printf("\t\t");
         gotoxy(58,12);
         printf("\t\t\t");
         gotoxy(58,12);
         textcolor(WHITE);
         }
         else
            break;
         }while(1);
         gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date (dd/mm/yyyy):");
     textcolor(WHITE);
    do
    {
        fflush(stdin);
        scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        int datevalid = isValidDate(CC.ed);
         if(CC.sd.tm_mday>CC.ed.tm_mday || CC.sd.tm_mon>CC.ed.tm_mon || CC.sd.tm_year>CC.ed.tm_year)
            datevalid=0;
          if(datevalid!=1)  //if(datevalid==1)
          {
                //break;
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date !");
         getch();
         gotoxy(27,18);
         printf("\t\t\t\t\t\t");
         gotoxy(55,13);
         printf("\t\t\t\t\t\t\t");
         gotoxy(55,13);
         textcolor(WHITE);
          }
          else
            break;
         }while(1);
         //Now validdate the dates against current date as well as against each other
         FILE *fp=fopen("Customer.bin","ab");  //ab file m data write karege konse file m data write karege Customer_car_detail
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
         printf("Booking done for Car %d",CC.car_id);
         printf("\nPress any key to continue");
         getch();
         fclose(fp);
         updateCarCount( c );
         bookedCarDetails();
         return 1;
}

void availableCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTEAL SYSTEM\n");
         textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
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
       printf("Car ID\t   Model\t\tCapacity\tAvailable\tPrice/Day");
       gotoxy(1,9);
    for(i=1; i<=80; i++)
        printf("%c",247);
     int row=10;
     textcolor(YELLOW);
     while(fread(&C,sizeof(C),1,fp)==1)
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
     getch();
     fclose(fp);
}

void CarReturn()
{
    FILE *fp=fopen("customer.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry! cannot open the file");
        return ;
    }
    Customer_Car_Details CC;
    time_t obj=time(0);
    struct tm *p=localtime(&obj);
    p->tm_year=1900+  p->tm_year;
    p->tm_mon=1+  p->tm_mon;
    while(fread(&CC,sizeof(CC),1,fp)==1)
    {
        if(CC.ed.tm_mday==CC.ed.tm_mday && CC.ed.tm_mon==CC.ed.tm_mon && CC.ed.tm_year==CC.ed.tm_year)
        {
             updateCarCount2(CC.car_id);
             deleteCarCount();
        }
    }
    fclose(fp);
}

void updateCarCount2(int id)
{
    FILE *fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry! cannot open the file");
        return ;
    }
    Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==id)
            {
                fseek(fp,(signed int)-(sizeof(C)),SEEK_CUR);
                C.car_count++;
                fwrite(&C,sizeof(C),1,fp);
                break;
            }
    }
    fclose(fp);
}

void  deleteCarCount( Customer_Car_Details CC)
{
    printf("Delete car called\n");
    getch();
    int flag=0;
    Customer_Car_Details CC2;
    FILE *fp1=fopen("customer.bin","rb+");
    if(fp1==NULL)
    return ;
    FILE *fp2=fopen("temp.bin","wb+");
    if(fp2==NULL)
        return ;
    while(fread(&CC2,sizeof(CC2),1,fp2)==1)
    {
        printf("Delet car called 1\n");
        getch();
        if(strcmp(CC.cust_name,CC2.cust_name)==0 && strcmp(CC.pickup,CC2.pickup)==0 &&
           strcmp(CC.drop,CC2.drop)==0 && CC.car_id==CC2.car_id && CC.sd.tm_mday==CC2.sd.tm_mday &&
           CC.sd.tm_mon==CC2.sd.tm_mon && CC.sd.tm_year && CC2.sd.tm_year && CC.ed.tm_mday==CC2.ed.tm_mday &&
           CC.ed.tm_mon == CC2.ed.tm_mon && CC.ed.tm_year== CC2.ed.tm_year)
        {
            printf("Delete car called 2\n");
            flag=1;
            getch();
            continue;
        }
        else
        {
            printf("Delete car called 3\n");
            getch();
            fwrite(&CC2,sizeof(CC2),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==1)
    {
        return ;
    }
    fp1=fopen("customer.bin","wb+");
    fp2=fopen("temp.bin","rb");
    while(fread(&CC2,sizeof(CC2),1,fp2)==1);
    {
        fwrite(&CC2,sizeof(CC2),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
}
