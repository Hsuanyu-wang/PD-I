#include<stdio.h>

int main(void)
{
    int m;
    printf("Enter a dollar amount:/n");
    scanf("%d" ,&m);
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n" ,m/20 ,(m%20)/10 ,(m%10)/5 ,(m%5)/1);
    return 0;
}
