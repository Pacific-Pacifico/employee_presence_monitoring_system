#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

void admin_mode()
{   
    int option;
    char ch;
    do
    {
        printf("\n\n*****Admin mode*****");
        printf("\nSelect the required option:");
        printf("\n1.Number of employees came today");
        printf("\n2.Check particular employee's attendance of today");
        printf("\n3.Number of times entrance of particular employee");
        printf("\n4.Employee that moves out most number of times");
        printf("\n5.Name of the employees out for particular time period");
        printf("\n6.Employees who came within range of ids and how often they entered");
        printf("\n7.Change admin password");
        printf("\n8.Go to main menu");
        printf("\n9.Exit");
        printf("\nEnter the option=");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                count_attendance();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                return;

            case 9:
                exit(1);

            default:
                printf("\nInvalid option selected!!!");
        }
        printf("\n\nEnter y/Y and press enter to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');
}

void count_attendance()
{
    int i,count=0;
    for(i=0;i<TOTAL_EMPLOYEES;i++)
        if(employees[i].counter>=1)
            count++;
    printf("\nNumber of employees came today= %d",count);
}

void add_employee()
{
    struct Employee emp;
    printf("\nEnter employee id=");
    scanf("%d",&emp.emp_id);
    fflush(stdin);
    printf("\nEnter employee name=");
    fgets(emp.name,50,stdin);
    printf("\nEnter age=");
    scanf("%d",&emp.age);
    printf("\nEnter contact number=");
    scanf("%lu",&emp.contact_number);
    fflush(stdin);
    printf("\nEnter address=");
    fgets(emp.address,50,stdin);
    emp.counter=-1;
    append_to_file("./employee_details.dat",&emp);
    printf("\nNew employee details successfully witten to 'employee_details.dat' file");
}