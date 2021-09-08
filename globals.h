#define TOTAL_EMPLOYEES 10 

struct Employee
{
    int emp_id,age,counter;
    unsigned long contact_number; 
    char name[50],address[100];
};

struct Employee employees[TOTAL_EMPLOYEES];

void read_employees();
int search(int);
void employee_mode();
void mark_attendance();
void move_out();
void move_in();
void show_employee_details();


void admin_mode();
void add_employee();
void show_employee();
void count_attendance();

void append_to_file(char file_path[],struct Employee *ptr);
void read_from_file(char file_path[]);
int count_records(char file_path[]);

unsigned long get_timestamp();
char *convert_timestamp_to_time(unsigned long timestamp);
void clear();
