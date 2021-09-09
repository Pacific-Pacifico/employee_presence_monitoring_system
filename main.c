#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

int total_employees;
struct Employee *employees;

int main()
{
    int option;
    char ch;
    total_employees=count_records("./employees_details.dat");
    printf("\nTotal number of employees= %d",total_employees);
    employees=(struct Employee *)calloc(total_employees,sizeof(struct Employee));
    read_all_employees_from_file("./employees_details.dat");
    do
    {
        clear();
        printf("\nEMPLOYEE PRESENCE MONITORING SYSTEM");
        printf("\nSelect the required option:");
        printf("\n1.Employee mode");
        printf("\n2.Admin mode");
        printf("\n3.Exit");
        printf("\nEnter the option=");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                employee_mode();
                break;

            case 2:
                admin_mode();       
                break;

            case 3:
                exit(1);
                
            default:
                printf("\nInvalid option selected!!!");
        }
        printf("\n\nEnter y/Y and press enter to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');
}

void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}