#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ranum()
{
    int r;
    srand(time(NULL));
    r=rand();
    return (r%9);
}

void print_T(int T[])
{
    for(int i=0; i<9; i++)
    {
            if(T[i]==-1)
                printf("X | ");
            else if(T[i]==0)
                printf("O | ");
            else
                printf("%d | ",T[i]);
        if((i+1)%3==0)
            printf("\n_   _   _\n");
    }
}

int* input_T(int n,int T[],int p)
{
    if(p==-1)
    {
        if(T[n]==0 || T[n]==-1)
        {
            int k;
           printf("occupied\n");
                printf("Player-1==>");
                scanf("%d",&k);
                T=input_T(k-1,T,-1);
        }

        else
        T[n]=-1;
    }
    else if(p==0)
    {
        if(T[n]==0 || T[n]==-1)
        {
            int b;
            b=ranum();
            while(b==n)
            {
                b=ranum();
            }
            T[b]=0;
        }
        else
            T[n]=0;
    }
    return T;
}

void player_1_turn(int T[])
{
    int n;
    printf("Player-1==>");
    scanf("%d",&n);
    T=input_T(n-1,T,-1);
    print_T(T);
}

void player_2_turn(int T[])
{
    int n;
    n=ranum();
    printf("Player-2==>%d\n",n+1);
    T=input_T(n,T,0);
    print_T(T);
}

int check_same(int T[])
{
    for(int i=0; i<3; i++)
    {
        if(T[i] == T[i+1] && T[i+1] == T[i+2])
        {
            check_XO(T[i]);
            return 1;
        }
    }
    for(int i=0;i<8;i+=3)
    {
        if(T[i] == T[i+1] && T[i+1] == T[i+2])
        {
            check_XO(T[i]);
            return 1;
        }
    }
    if(T[0] == T[4] && T[4] == T[8])
    {
        check_XO(T[0]);
        return 1;
    }
    if(T[2] == T[4] && T[4] == T[6])
    {
        check_XO(T[2]);
        return 1;
    }
}

void check_XO(int t)
{
    if(t==-1)
    {
        printf("player-1 win");
    }
    else if(t==0)
    {
        printf("player-2 win");
    }
}

int main()
{
    int n=0,a=0;
    int T[9]= {1,2,3,4,5,6,7,8,9};
    printf("Player-1==>X\nPlayer-2==>O\n\n");
    print_T(T);
    while(a!=1)
    {
        player_1_turn(T);
        //print_T(T);
        a=check_same(T);
        if(a==1)
            break;
        player_2_turn(T);
        //print_T(T);
        a=check_same(T);
    }
    return 0;
}
