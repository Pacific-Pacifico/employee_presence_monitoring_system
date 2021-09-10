#include <termios.h>
#include <unistd.h>
#include <stdio.h>
 
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

int main()
{
    // char ch1,ch2;
    // ch1=getch();
    // ch2=getche();
    // printf("\nch1=%c",ch1);
    // printf("\nch2=%c",ch2);

    char ch,password[55];
  
    printf("password:\n");
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
    printf("\nYou have entered %s as password.",password);
    getch();
}