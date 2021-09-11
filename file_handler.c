#include<stdio.h>
#include<string.h>
#include"globals.h"

void write_str_to_file(char file_path[],char str[])
{
    // open file for writing
    FILE *fout=fopen(file_path, "w");
    if (fout == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }
    fwrite(str,strlen(str),1,fout);
    if(fwrite != 0) 
        printf("\nContents to file written successfully !\n");
    else 
        printf("\nError writing file !\n");
    // close file
    fclose(fout);
}

char *read_str_from_file(char file_path[])
{
    static char str[21];
    str[0]='\0';
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return str;
    }
    fread(str, 21, 1, fin);
    
    // close file
    fclose(fin);
    return str;
}

void append_to_file(char file_path[],struct Employee *ptr)
{ 
    // open file for appending
    FILE *fout=fopen(file_path, "a");
    if (fout == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }
    fwrite(ptr,sizeof(struct Employee),1,fout);
    if(fwrite != 0) 
        printf("\nContents to file written successfully !\n");
    else 
        printf("\nError writing file !\n");
    // close file
    fclose(fout);
}

void read_from_file(char file_path[])
{
    struct Employee emp;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }

    // read file contents till end of file
    while(fread(&emp, sizeof(struct Employee), 1, fin))
        show_employee_details(emp);
  
    // close file
    fclose(fin);
}

void read_all_employees_from_file(char file_path[])
{
    int i;
    struct Employee emp;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }
    i=0;
    // read file contents till end of file
    while(fread(&emp, sizeof(struct Employee), 1, fin))
    {
        employees[i]=emp;
        i++;
    }
    // close file
    fclose(fin);
}

int count_records(char file_path[])
{
    struct Employee emp;
    int count=0;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        // fprintf(stderr, "\nError opening file\n");
        return 0;
    }

    // read file contents till end of file
    while(fread(&emp, sizeof(struct Employee), 1, fin))
        count++;
  
    // close file
    fclose(fin);
    return count;
}