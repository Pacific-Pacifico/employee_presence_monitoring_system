#include<stdio.h>
#include<stdlib.h>
#include "globals.h"

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <termios.h>
    #include <unistd.h>
        /* reads from keypress, doesn't echo */
    int getch(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }

    /* reads from keypress, and echoes */
    int getche(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }

#endif

char *get_pass()
{
    char ch,*password;
    password=(char *)malloc(sizeof(char)*20);
    if(password==NULL)
    {
        printf("\nNot enough memory!!!");
        return NULL;
    }
    // printf("password:\n");
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==NEW_LINE)
            break;
        printf("*");
        password[i]=ch;
        i++;
    }
    password[i]='\0';
    return password;
}
