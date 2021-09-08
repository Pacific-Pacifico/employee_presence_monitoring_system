#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

void employee_mode()
{
    int option;
    char ch;
    do
    {
        printf("\n\n*****Employee mode*****");
        printf("\nSelect the required option:");
        printf("\n1.Mark attendance");
        printf("\n2.Move out");
        printf("\n3.Move in");
        printf("\n4.Go to main menu");
        printf("\n5.Exit");
        printf("\nEnter the option=");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                mark_attendance();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                return;

            case 5:
                exit(1);

            default:
                printf("\nInvalid option selected!!!");
        }
        printf("\n\nEnter y/Y and press enter to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');
}

int search(int id)
{
    int i;
    for(i=0;i<TOTAL_EMPLOYEES;i++)
    {
        if(employees[i].emp_id==id)
            return i;
    }
    return -1;
}

void mark_attendance()
{   
    int id,index;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    employees[index].counter=1;
}

void move_out()
{
    int id,index;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    employees[index].counter++;
}

void move_in()
{
    int id,index;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    employees[index].counter++;
}