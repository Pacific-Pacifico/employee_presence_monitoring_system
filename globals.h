#define TOTAL_EMPLOYEES 20 

struct Employee
{
    int emp_id,age,counter;
    unsigned long contact_number; 
    char address[100];
};

struct Employee employees[TOTAL_EMPLOYEES];

void employee_mode();
void admin_mode();
void clear();
