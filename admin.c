#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"

int check_admin_pass(char entered_pass[])
{
    if(strcmp(entered_pass,admin_pass)==0)
        return 1;
    return 0;
}

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
                time_period_out();
                break;

            case 6:
                range_ids();
                break;

            case 7:
                change_admin_pass();
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

void time_period_out()
{
    short h1,m1,s1,h2,m2,s2;
    printf("\nEnter starting hour(0-23)=");
    scanf("%hu",&h1);
    printf("\nEnter starting minute(0-59)=");
    scanf("%hu",&m1);
    printf("\nEnter starting second(0-59)=");
    scanf("%hu",&s1);

    printf("\nEnter ending hour(0-23)=");
    scanf("%hu",&h2);
    printf("\nEnter ending minute(0-59)=");
    scanf("%hu",&m2);
    printf("\nEnter ending second(0-59)=");
    scanf("%hu",&s2);

    printf("\nEmployees outside from %hu:%hu:%hu to %hu:%hu:%hu :",h1,m1,s1,h2,m2,s2);
    
}

void range_ids()
{
    int low,high,i,found=0,total,n;
    printf("\nEnter lowest id=");
    scanf("%d",&low);
    printf("\nEnter highest id=");
    scanf("%d",&high);
    for(i=low;i<=high && i<total_employees+1;i++)
    {
        found=1;
        show_employee_details(employees[i-1]);
        total=employees[i-1].counter;
        if(total==0)
        {
            printf("\nNot present");
            continue;
        }
        if(total%2!=0)
            n=(total/2)+1;
        else
            n=total/2;
        printf("\n\nNo of times entered= %d",n);       
    }
    if(!found)
        printf("\nNo employee id within provided range.");
}

void change_admin_pass()
{
    char cur_pass[21],p1[21],p2[21],*p;
    printf("\nEnter current password = ");
    while ((getchar()) != '\n');
    p=get_pass();
    strcpy(cur_pass,p);
    free(p);
    if(strcmp(cur_pass,admin_pass)!=0)
    {
        printf("\nWrong password!!!");
        return;
    }
    printf("\nEnter new password(Max length=20) = ");
    p=get_pass();
    strcpy(p1,p);
    free(p);
    printf("\nConfirm password = ");
    p=get_pass();
    strcpy(p2,p);
    free(p);
    if(strcmp(p1,p2)!=0)
    {
        printf("\nPasswords didn't match!!!");
        return;
    }
    strcpy(admin_pass,p1);
    printf("\nPassword successfully changed.");
}

void add_employee()
{
    struct Employee emp;
    emp.emp_id=total_employees+1;
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
    printf("\nNew employee's generated id= %d",emp.emp_id);
    employees=realloc(employees,total_employees+1);
    employees[total_employees]=emp;
    total_employees++;
}

void all_employees_details()
{
    // read_from_file("./employees_details.dat");
    int i;
    printf("\nAll employees' details");
    for(i=0;i<total_employees;i++)
        show_employee_details(employees[i]);
}