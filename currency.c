#include<stdio.h>

int  main()
{
    int n,notes,choice;
    printf("Enter amount: ");
    scanf("%d",&n);
    printf("Enter the value of note from which you wants to begin: ");
    scanf("%d",&choice);
    switch(choice)
    {
 case 2000:
  notes=n/2000;
  n=n%2000;
  printf("\nNumber of 2000 notes: %d",notes);
 case 1000:
  notes=n/1000;
  n=n%1000;
  printf("\nNumber of 1000 notes: %d",notes);
 case 500:
  notes=n/500;
  n=n%500;
  printf("\nNumber of 500 notes: %d",notes);

 case 200:
  notes=n/200;
  n=n%200;
  printf("\nNumber of 200 notes: %d",notes);
 case 100:
  notes=n/100;
  n=n%100;
  printf("\nNumber of 100 notes: %d",notes);
 case 50:
  notes=n/50;
  n=n%50;
  printf("\nNumber of 50 notes: %d",notes);
 case 20:
  notes=n/20;
  n=n%20;
  printf("\nNumber of 20 notes: %d",notes);
 case 10:
  notes=n/10;
  n=n%10;
  printf("\nNumber of 10 notes: %d",notes);
 case 5:
  notes=n/5;
  n=n%5;
  printf("\nNumber of 5 notes: %d",notes);
  break;
 default:
  printf("\ninvalid value");
    }
    return 0;
}
