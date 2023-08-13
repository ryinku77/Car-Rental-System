#ifndef RINKUS_HEADER_H_INCLUDED
#define RINKUS_HEADER_H_INCLUDED
#include <time.h>
struct  User
{
char userid[20];
char pwd[20];
char name[20];
};
struct Car
{
int car_id;
char car_name[50];
int capacity;
int car_count;
int price;
};
/*struct Customer_Car_Details
{
    int car_id;
    char cust_name [30];
    char pickup[30];
    char drop [30];

};*/
struct Customer_Car_Details
{
    int Car_id;
    char cust_name[30];
     char pickup[30];
     char drop[30];
     struct tm sd ;
     struct tm ed;
};

typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;

void addAdmin();
User*getinput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetail();
int deleteEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void UpdateCarCount(int);
void bookedCarDetails();
char* getCarName(int);
int rentCar(); // int := tabhipta chalega booking hue ke nhi
void availableCarDetails();



#endif // RINKUS_HEADER_H_INCLUDED
