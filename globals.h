struct Employee
{
    int emp_id,age,counter;
    unsigned long contact_number; 
    char name[50],address[100];
};

extern struct Employee *employees;
extern int total_employees;

int search(int);
void employee_mode();
void mark_attendance();
void move_out();
void move_in();
void show_employee_details(struct Employee);
void all_employees_details();


void admin_mode();
void add_employee();
void count_attendance();
void check_particular_attendance();
void count_entrance();
void max_counter();

int count_records(char file_path[]);
void append_to_file(char file_path[],struct Employee *ptr);
void read_from_file(char file_path[]);
void read_all_employees_from_file(char file_path[]);
int count_records(char file_path[]);

unsigned long get_timestamp();
char *convert_timestamp_to_time(unsigned long timestamp);
void clear();
