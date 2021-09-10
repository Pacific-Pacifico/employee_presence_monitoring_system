#include <stdio.h>
#include<stdlib.h>
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

char *get_pass()
{
    char ch,*password;
    password=(char *)malloc(sizeof(char)*20);
    // printf("password:\n");
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch=='\n')
            break;
        printf("*");
        password[i]=ch;
        i++;
    }
    password[i]='\0';
    return password;
}