#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include "rinkus header.h"
int main()
{
    int i;
    int type,choice;
    User* usr;

    int k;
    int result;
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(GREEN);
    printf("*RENT A CAR AND GO WHENEVET YOU NEED*");
    getch();
    textcolor(YELLOW);
    addAdmin();

    while(1)
    {
        clrscr();
        textcolor(RED);
        gotoxy(32,2);
        printf("Car Rental System");
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0; i<80; i++)
        {
           printf("*");
        }
        gotoxy(1,18);
         for(i=0; i<80; i++)
        {
           printf("*");
        }
        gotoxy(32,10);
        textcolor(YELLOW);
        printf("1. Admin");
        gotoxy(32,12);
        printf("2. Employee");
        gotoxy(32,14);
        printf("3. Quit");
        gotoxy(32,16);
        textcolor(WHITE);
        printf("Select your role:");


        do
        {
             scanf("%d",&type);
             if(type==1)
             {
               do
                  {

                             usr=getinput();
                              if (usr==NULL)
                                   break;
                              else
                               {
                                    k=  checkUserExist(*usr, "admin");
                               }
                   }while(k==0);
                   if(k==-1)

                     break;
              if(k=1)
              {
                  gotoxy(1,20);
                  textcolor(WHITE);
                  printf("PRESS ANY KEY TO CONTINUE");
                  getch();

             while(1)

{

         clrscr();
    choice=adminMenu();

    if(choice==7)

        break;
    switch(choice)
    {
    case 1:
         clrscr();
        addEmployee();
        break;

    case 2:
          addCarDetails();
        break;
    case 3:
        viewEmployee();
        break;
    case 4:
        clrscr();
        //showCarDetail();
        break;
    case 5:
      clrscr();

      result=deleteEmp();
      gotoxy(15,14);
      if(result==0)
        {
            textcolor(LIGHTRED);
            printf("SORRY!no emp found for given for given emp id");
        }
        else if(result==1)
        {
            textcolor(LIGHTRED);
            printf("Record delete succesfully!");
        }
        else if(result==2)
        {
            textcolor(LIGHTRED);
            printf("sorry !Error in Deletion. try again!");
            }
            textcolor(WHITE);
            printf("\n\nPfress any key to go back to the main screen!");
            getch();
        break;
    case 6:
        deleteCarModel();
        break;

        default:
                printf("enter incorrect choice");
              }

        }
        }
             }  //missing
             else  if(type==2)
          {
do
                      {
                             usr=getinput();
                           if(usr==NULL)
                            break; //mistake missing
                           else
                           {
                                k=checkUserExist(*usr,"emp");
                           }
                      }while(k==0);
                 if(k==-1)
                   break;
                    if(k==1)
                     {
                           gotoxy(1,20);
                    textcolor(WHITE);
                   printf("Press any key to continue");
                        getch();
                          while(1)
                          {
                               clrscr();
                                   choice=empMenu();
                               if(choice==5)
                                     ////clrscr();  mistake
                                     break;
                             switch(choice)
                              {
                                case 1:
                                       clrscr();
                                       int rentresp;//rentresponse
                                       rentresp=rentCar();
                                       if(rentresp==-2)
                                       {
                                           gotoxy(35,9);
                                           textcolor(LIGHTRED);
                                           printf("Sorry!All cars booked.try agan latter");
                                              getch();
                                            }

                                       break;
                                case 2:
                                       clrscr();
                                    bookedCarDetail();
                                       break;
                                    case 3:
                                       clrscr();
                                         availableCarDetails();
                                       break;
                                   case 4:
                                       clrscr();
                                        showCarDetail();
                                       break;


                                    default:
                                      printf("Incorrect Choice:");

                        }//switch close
                        // if exit press go back to the role selction
                    }
                }
            } // type if close

              else  if(type==3)
             {
                 clrscr();
                 textcolor(GREEN);
                 gotoxy(30,12);
                 printf("Thank you for using the app ");
                 getch();
                 exit(0);

             }
             else
             {
                 textcolor(RED);
                 gotoxy(30,20);
                 printf("Invalid choice");
                 getch();
                 gotoxy(30,20);
                 printf("\t\t\t");
                 gotoxy(49,16);
                 printf("\t\t\t");
                 textcolor(WHITE);
                 gotoxy(49,16);
             }
        }while(1);
          getch();
        }
return 0;
}
