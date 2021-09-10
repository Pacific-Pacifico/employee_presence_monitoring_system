#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

void employee_mode()
{
    int option;
    char ch;
    do
    {
        clear();
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
                move_out();
                break;

            case 3:
                move_in();
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
    for(i=0;i<total_employees;i++)
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
    if(index==-1)
    {
        printf("\nId not found!!!");
        return;
    }
    if(employees[index].counter>=1)
    {
        printf("\nAttendance of id= %d is already marked.",id);
        return;
    }
    employees[index].counter=1;
    printf("\nAttendance of id= %d marked successfully.",id);
}

void move_out()
{
    int id,index,c;
    struct Time *t;
    printf("\nEnter employee id=");
    scanf("%d",&id);
    index=search(id);
    if(index==-1)
    {
        printf("\nId not found!!!");
        return;
    }
    c=employees[index].counter;
    if(c==0)
    {
        printf("\nPlease mark your attendance first.");
        return;
    }
    if(c%2==0)
    {
        printf("\nYou are already outside office.");
        return;
    }

    t=convert_timestamp_to_time(get_timestamp());
    if(c==1)
    {
        out_time[index]=insert_beg(out_time[index],t);
    }
    else
    {
        out_time[index]=insert_end(out_time[index],t);
    }

    employees[index].counter++;
    printf("\nYou can now move out.");
    
    show_out_times(out_time[index]);
}

void move_in()
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
    if(employees[index].counter==0)
    {
        printf("\nPlease mark your attendance first.");
        return;
    }
    if((employees[index].counter)%2!=0)
    {
        printf("\nYou are already inside office.");
        return;
    }
    employees[index].counter++;
    printf("\nYou can now move in.");
}

void show_employee_details(struct Employee emp)
{
    printf("\n\n--Employee--");
    printf("\nEmployee id: %d",emp.emp_id);
    printf("\nEmployee name: %s",emp.name);
    printf("\nEmployee age: %d",emp.age);
    printf("\nEmployee contact number: %ld",emp.contact_number);
    printf("\nEmployee address: %s",emp.address);
}