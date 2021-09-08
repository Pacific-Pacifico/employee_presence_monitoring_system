#define TOTAL_EMPLOYEES 10 

struct Employee
{
    int emp_id,age,counter;
    unsigned long contact_number; 
    char address[100];
};

struct Employee employees[TOTAL_EMPLOYEES];

int search(int);
void employee_mode();
void mark_attendance();
void move_out();
void move_in();


void admin_mode();
void show_employee();
void count_attendance();

unsigned long get_timestamp();
char *convert_timestamp_to_time(unsigned long timestamp);
void clear();
