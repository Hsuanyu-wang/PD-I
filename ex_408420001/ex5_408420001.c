#include<stdio.h>
int main(void)
{
    int b=10,s=2,g=1,m,v=1,d=0,f=0;
    printf("Welcome, Adventurer!\n");
    while(1)
    {
        printf("Do you want to go to our village first (1: Yes; 0: No)?\n");
        scanf("%d",&v);
        d=0,f=0;
        if(v==0)
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
            if(g==0)
            {
                printf("We will miss you. Bye!\n");
                break;
            }
            else if(b<=0)
            {
                printf("You Dead. Bye!\n");
                break;
            }
        }
        if(v==1)
        {
            while(d!=3)
            {
                printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)?\n");
                scanf("%d",&d);
                if(d == 1 && f == 0)
                {
                    s++;
                    printf("Nice sword! Now you have %d strength!\n",s);
                    f=1;
                }
                else if(d == 1 && f == 1 )
                {
                    printf("You already brought a sword.\n");
                }
                else if(d == 2  && b<10)
                {
                    printf("Nice beer! Now you have %d blood!\n",++b);
                }
                else if(d == 2 && b>=10)
                {
                    printf("Your blood is full. You don't need a beer.\n");
                }
                else if (d == 3)
                {
                    printf("You are welcome to come back anytime!\n");
                }
                else
                    printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
            }
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
            if(g==0)
            {
                printf("We will miss you. Bye!\n");
                break;
            }
            else if(b<=0)
            {
                printf("You Dead. Bye!\n");
                break;
            }
        }
    }
    return 0;
}
