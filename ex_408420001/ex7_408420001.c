#include<stdio.h>
#include<string.h>

int main(void)
{
    int n,x,y,vx,vy;
    //map
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d",&x,&y);
    int map[x][y]={false,false};
//    for(int i=0; i<x; i++)
//        for(int j=0; j<y; j++)
//            map[i][j]=0;
    //village
    while(1)
    {
        printf("Input the row and column for the village location:\n");
        scanf("%d %d",&vx,&vy);
        if(vx >= 0 && vx < x && vy >= 0 && vy < y)
        {
            map[vx][vy]=1;
            break;
        }
        else
            printf("the location is outside the map\n");
    }
    //monster
    n=x%10+x/10;
    int mx,my;
    printf("You need to assign location for %d monsters in total\n",n);

    for(int i=0; i<n; i++)
    {
        while(1)
        {
            printf("Input the row and column for monster %d:\n",i);
            scanf("%d %d",&mx,&my);
            if(map[mx][my] == 0)
            {
                map[mx][my]=2;
                break;
            }
            else
            {
                printf("the location is occupied\n");
            }
        }
    }
    //map
    printf("=== MAP ===\n");
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(map[i][j]==1)
                printf("v ");
            else if(map[i][j]==2)
                printf("m ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
    return 0;
}
