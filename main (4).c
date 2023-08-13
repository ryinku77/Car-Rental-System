include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include "car.h"

int main()
{
    int i,choice,result;
    int type;
    User *usr;
    int k;
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
                            usr = getlnput();    // code for Admin
                              if (usr==NULL)
                                   break;     // it will NULL or user* if NULL so break if user* (user id or pwd) the check correct or not by  checkUserExist(); function.
                              else
                               {
                                    k=  checkUserExist(*usr, "admin");        // call for checkUserExist();  // yeh 1 or 0 return karega 0 kareaga toh or chance milna chaheye user ko or 1 karega to valid hai.
                               }
                   }while(k==0);                 //id yah pwd wrong
                   if(k==-1)                         //file not open any problem
                     break;
                   if(k==1)                        //loging ho gya
                   {
                       gotoxy(1,20);
                       textcolor(WHITE);
                       printf("Press any key to continue");
                       _getch();
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
                                              addEmployee(); //  addEmployee();
                                                    break;
                            case 2:
                                                    clrscr();
                                                      addCarDetails();  // addCarDetails();
                                                    break;
                            case 3:
                                                    clrscr();
                                                     viewEmployee();  // viewEmployee();
                                                    break;
                            case 4:
                                                        clrscr();
                                                     showCarDetails();  //   showCarDetails();
                                                    break;
                            case 5:
                                                      clrscr();
                                                      result=deleteEmp();
                                                      gotoxy(15,14);
                                                      if(result==0)
                                                      {
                                                          textcolor(LIGHTRED);
                                                          printf("Sorry ! no record of the given emp found");  // record nhi mila
                                                      }
                                                      else if (result==1)
                                                      {
                                                          textcolor(LIGHTGREEN);
                                                          printf("Record deleted successfully");
                                                      }
                                                      else if (result==2)
                                                      {
                                                            textcolor(LIGHTRED);
                                                            printf("Error in deletion");
                                                      }
                                                      textcolor(WHITE);
                                                     printf("\n\nPress any key to go back to the menu");
                                                     getch();
                                                    break;
                             case 6:
                                                     clrscr();
                                                     result=deleteCarModel();
                                                     gotoxy(15,14);
                                                      if(result==0)
                                                      {
                                                          textcolor(LIGHTRED);
                                                          printf("Sorry ! no record of the given id found");  // record nhi mila
                                                      }
                                                      else if (result==1)
                                                      {
                                                          textcolor(LIGHTGREEN);
                                                          printf("Record deleted successfully");
                                                      }
                                                      else if (result==2)
                                                      {
                                                            textcolor(LIGHTRED);
                                                            printf("Error in deletion");

                                                      }
                                                      textcolor(WHITE);
                                                     printf("\n\nPress any key to go back to the menu");
                                                     getch();
                                                    break;
                            default:
                                                    break;
                            }
                       }
                   }
             }
             else  if(type==2)
             {
                 // code for Employee
                         do
                  {
                            usr = getlnput();    // code for Admin
                              if (usr==NULL)
                                   break;     // it will NULL or user* if NULL so break if user* (user id or pwd) the check correct or not by  checkUserExist(); function.
                              else
                               {
                                    k=  checkUserExist(*usr, "emp");        // call for checkUserExist();  // yeh 1 or 0 return karega 0 kareaga toh or chance milna chaheye user ko or 1 karega to valid hai.
                               }
                   }while(k==0);                 //id yah pwd wrong
                   if(k==-1)                         //file not open any problem
                     break;
                   if(k==1)                        //loging ho gya
                   {
                       gotoxy(1,20);
                       textcolor(WHITE);
                       printf("Press any key to continue");
                       _getch();
                       while(1)
                       {
                           clrscr();
                            choice=empMenu();
                            if(choice==5)
                            {
                                clrscr();
                                  break;
                            }
                            switch(choice)
                            {
                            case 1:
                                               clrscr();
                                                int rentresp;
                                                rentresp=  rentCar();
                                                if(rentresp==-2)
                                                {
                                                    gotoxy(35,9);
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry! All cars booked. Try later");
                                                    getch();
                                                   // break;
                                                }
                                                else if(rentresp==0)
                                                {
                                                        gotoxy(27,18);     //kuch car print hue hog
                                                    textcolor(LIGHTRED);
                                                    printf("You did not choose any car");
                                                    getch();

                                                }
                                                   break;

                            case 2:
                                                    clrscr();
                                                      bookedCarDetails();
                                                    break;
                            case 3:
                                                    clrscr();
                                                    availableCarDetails();
                                                    break;
                            case 4:
                                                        clrscr();
                                                         showCarDetails();
                                                    break;
                            case 5:
                                                   clrscr();
                                                   getch();
                                                   break;
                            case 6:
                                             CarReturn();
                            default:
                                     printf("incorrect choice:");
                                                    break;
                            }
                       }
                   }
             }
              else  if(type==3)
             {
                 clrscr();
                 textcolor(GREEN);
                 gotoxy(30,12);
                 printf("Thank you for using the app ");
                 getch();
                 exit(0);   //  code to band karne ke liye

             }
             else
             {
                 textcolor(RED);
                 gotoxy(30,20);
                 printf("Invalid User type");
                 getch();
                 gotoxy(30,20);   // cursor will go at the begning of "invalid" I
                 printf("\t\t\t");   // we will printf spaces at the place of "invalid choice"
                 gotoxy(49,16);     //   cursor will go at the "Select your role: _ this place"
                 printf("\t\t\t");    // we will printf space at the place of 3
                 textcolor(WHITE);
                 gotoxy(49,16);   // again  we will  go to the cursor at the "Select your role: _ this place"
             }
             if(choice==7 || choice==5)
                break;
        }while(1);

    }
    getch();
    return 0;
}
