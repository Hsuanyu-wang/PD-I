#include<stdio.h>
int main(void)
{
    int b=10,s=2,g=1,m;
    printf("Welcome, Adventurer!\n");
    while(b>0 && g==1)
    {
        printf("You have %d blood and %d strength.\n",b,s);
        printf("Please choose which monster (1 to 4) you want to fight:\n");
        scanf("%d",&m);
        while(m<1||m>4)
        {
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
            scanf("%d",&m);
        }
        printf("You are fighting Monster %d!\n",m);
        if(s>m)
        {
            printf("You win\n");
            s++;
        }
        else if(s<=m)
        {
            printf("You Lose\n");
            b-=m;
        }
        printf("Do you want to go on your adventure (1:Yes;0: No) ?:\n");
        scanf("%d",&g);
    }
    if(g==0)
        printf("We will miss you. Bye!\n");
    else if(b<=0)
        printf("You Dead. Bye!\n");
    return 0;
}
