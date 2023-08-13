#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct User
{
    char userid [20];
    char pwd [20];
    char name [20];
};
struct Car
{
    int car_id;
    char car_name [50];
    int capacity;
    int car_count;
    int price;
};
struct Customer_Car_Details
{
    int car_id;
    char cust_name [30];
    char pickup[30];
    char drop [30];
    struct tm sd;
    struct tm ed;
};
typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;


void addAdmin();
User * getlnput();
int checkUserExist(User, char*);  // char* file ka name hai 2 file h 1) "admin.bin" or "emp.bin"  agar admin ke file open karna h toh "admin" likhege or agar employee ke karna h toh "emp" likhege
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int empMenu();
int SelectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails();
char* getCarName(int);
int rentCar(); // int := tabhipta chalega booking hue ke nhi
void availableCarDetails();
void CarReturn();
void updateCarCount2(int);
void  deleteCarCount();

#endif // CAR_H_INCLUDED
