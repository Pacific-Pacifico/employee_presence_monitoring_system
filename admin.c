#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

void admin_mode()
{   
    int option;
    char ch;
    do
    {
        clear();
        printf("\n\n*****Admin mode*****");
        printf("\nSelect the required option:");
        printf("\n1.Number of employees came today");
        printf("\n2.Check particular employee's attendance of today");
        printf("\n3.Number of times entrance of particular employee");
        printf("\n4.Employee that moves out most number of times");
        printf("\n5.Name of the employees out for particular time period");
        printf("\n6.Employees who came within range of ids and how often they entered");
        printf("\n7.Change admin password");
        printf("\n8.Add employee");
        printf("\n9.Get all employees details");
        printf("\n10.Go to main menu");
        printf("\n11.Exit");
        printf("\nEnter the option=");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                count_attendance();
                break;

            case 2:
                check_particular_attendance();
                break;

            case 3:
                count_entrance();
                break;

            case 4:
                max_counter();
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                add_employee();
                break;

            case 9:
                all_employees_details();
                break;

            case 10:
                return;

            case 11:
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
    for(i=0;i<total_employees;i++)
        if(employees[i].counter>=1)
            count++;
    printf("\nNumber of employees came today= %d",count);
}

void check_particular_attendance()
{
    int id,index;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    if(index==-1)
    {
        printf("\nId not found!!!");
        return;
    }
    if(employees[index].counter>=1)
        printf("\nEmployee with id= %d is present today.",id);
    else
        printf("\nEmployee with id= %d is absent today.",id);
}

void count_entrance()
{
    int id,index,n,total;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    if(index==-1)
    {
        printf("\nId not found!!!");
        return;
    }
    total=employees[index].counter;
    if(total%2!=0)
        n=(total/2)+1;
    else
        n=total/2;
    printf("\nEmployee with id= %d has %d number of entrances.",id,n);
}

void max_counter()
{
    int i,max_index=0,max;
    printf("\nEmployees with max number of moving out:");
    for(i=1;i<total_employees;i++)
    {
        if(employees[i].counter>employees[max_index].counter)
            max_index=i;
    }
    max=employees[max_index].counter;
    show_employee_details(employees[max_index]);
    for(i=0;i<total_employees;i++)
    {
        if(i==max_index)
            continue;
        if(employees[i].counter==max)
            show_employee_details(employees[i]);
    }
}

void add_employee()
{
    struct Employee emp;
    printf("\nEnter employee id=");
    scanf("%d",&emp.emp_id);
    while ((getchar()) != '\n');
    printf("\nEnter employee name=");
    fgets(emp.name,50,stdin);
    printf("\nEnter age=");
    scanf("%d",&emp.age);
    printf("\nEnter contact number=");
    scanf("%lu",&emp.contact_number);
    while ((getchar()) != '\n');
    printf("\nEnter address=");
    fgets(emp.address,50,stdin);
    emp.counter=0;
    printf("\n\nEmployee details:");
    show_employee_details(emp);
    append_to_file("./employees_details.dat",&emp);
    printf("\nNew employee details successfully witten to 'employees_details.dat' file");
}

void all_employees_details()
{
    // read_from_file("./employees_details.dat");
    int i;
    printf("\nAll employees' details");
    for(i=0;i<total_employees;i++)
        show_employee_details(employees[i]);
}