#include<stdio.h>
#include<stdlib.h>
//declare structure type
struct MTX
{
    int** map;
    int r;
    int c;
    int pr;
    int pc;
};
//0:.(space) 1:village 2:monster 3:player

struct MTX create_map(void)
{
    struct MTX m;
    int x=0,y=0;
    //map
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d",&x,&y);
    m.r=x;
    m.c=y;
    m.pr=-1;
    m.pc=-1;
    //set matrix
    m.map=malloc(sizeof(int*)*x);
    for(int i=0; i<x; i++)
    {
        m.map[i]=malloc(sizeof(int)*y);
    }
    //initialize
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            m.map[i][j]=0;
    return m;
}

void print_map(struct MTX m)
{
    int x=m.r;
    int y=m.c;
    printf("=== MAP ===\n");
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(m.map[i][j] == 1)
                printf("v ");
            else if(m.map[i][j] == 2)
                printf("m ");
            else if(m.map[i][j] == 3)
                printf("p ");
            else if(m.map[i][j] == 0)
                printf(". ");
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
}
void setup_village(struct MTX m)
{
    int vx=0,vy=0;
    int x=m.r;
    int y=m.c;
    while(1)
    {
        printf("Input the row and column for the village location:\n");
        scanf("%d %d",&vx,&vy);
        if(vx < 0 || vx >= x || vy < 0 || vy >= y)
        {
            check_boundary(m);
        }
        else
        {
            m.map[vx][vy]=1;
            break;
        }
    }
}
void setup_monster(struct MTX m)
{
    int x=m.r;
    int y=m.c;
    int n=0,i=0;
    n=x%10+x/10;
    int mx=0,my=0;
    while(i<n)
    {
        printf("You need to assign location for %d monsters in total\n",n);
        printf("Input the row and column for monster %d:\n",i);
        scanf("%d %d",&mx,&my);
        if(check_boundary(m,mx,my) && check_availability(m,mx,my))
        {
            m.map[mx][my]=2;
            i++;
        }
    }
}
struct MTX setup_player(struct MTX m)
{
    int x=m.r;
    int y=m.c;
    int px=0,py=0;
    while(1)
    {
        printf("Input the row and column for player:\n");
        scanf("%d %d",&px,&py);
        if(check_boundary(m,px,py) && check_availability(m,px,py))
        {
            m.pr=px;
            m.pc=py;
            m.map[px][py]=3;
            break;
        }
        else
        {
            printf("check error\n");
            break;
        }
    }
    return m;
}
//check definition
int check_boundary(struct MTX m,int x,int y)
{
    if(x<0 || y<0 || x>=m.r || y>=m.c)
    {
        printf("the location is outside the map\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
int check_availability(struct MTX m,int x,int y)
{
    if(m.map[x][y] == 1 || m.map[x][y] == 2)
    {
        printf("the location is occupied\n");
        return 0;
    }
    else
        return 1;
}
void check_move()
{
//    if(m.map[m.pr][m.pc] != 0)
        printf("you can't go there\n");
//    else if(m.map[x][y] == 2)

}
//movement definition
struct MTX go_up(struct MTX m)
{
    int x=m.pr,y=m.pc;
    if((x-1) < 0 || m.map[x-1][y] != 0)
        check_move();
    else
    {
        m.pr--;
        m.map[x-1][y] = 3,m.map[x][y] = 0;
        print_map(m);
    }
    return m;
}
struct MTX go_down(struct MTX m)
{
    int x=m.pr,y=m.pc,bx=m.r,by=m.c;
    if((x+1) >= bx || m.map[x+1][y] != 0)
        check_move();
    else if(m.map[x+1][y] == 0)
    {
        m.pr++;
        m.map[x+1][y] = 3,m.map[x][y] = 0;
        print_map(m);
    }
    return m;
}
struct MTX go_left(struct MTX m)
{
    int x=m.pr,y=m.pc;
    if((y-1) < 0 || m.map[x][y-1] != 0)
        check_move();
    else
    {
        m.pc--;
        m.map[x][y-1] = 3,m.map[x][y] = 0;
        print_map(m);
    }
    return m;
}
struct MTX go_right(struct MTX m)
{
    int x=m.pr,y=m.pc,bx=m.r,by=m.c;
    if(((y+1) >= by) || (m.map[x][y+1] != 0))
        check_move();
    else
    {
        m.pc++,m.map[x][y+1] = 3,m.map[x][y] = 0,print_map(m);
    }
    return m;
}
//option definition
struct MTX move_option(struct MTX mtx)
{
    int slct_pen;
    printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
    scanf("%d",&slct_pen);
    if(slct_pen == 1)
        mtx=go_up(mtx);
    else if(slct_pen == 2)
        mtx=go_down(mtx);
    else if(slct_pen == 3)
        mtx=go_right(mtx);
    else if(slct_pen == 4)
        mtx=go_left(mtx);
    else if(slct_pen == 5)
        exit(0);
    else
        printf("move option error\n");
    return mtx;
}
struct MTX map_option(struct MTX mtx)
{
    int slct_eth;
    printf("[1] Create a new map [2] Start travel the map: ");
    scanf("%d",&slct_eth);
    //new map
    if(slct_eth == 1)
    {
        mtx=create_map(),setup_village(mtx),setup_monster(mtx),print_map(mtx);
    }
    //travel
    else if(slct_eth == 2)
    {
        mtx=setup_player(mtx),print_map(mtx);
        while(1)
            mtx=move_option(mtx);
    }
    else
    {
        printf("map option error\n"),exit(0);
    }
    return mtx;
}

int main(void)
{
    struct MTX mtx;
    mtx=create_map(),setup_village(mtx),setup_monster(mtx),print_map(mtx);
    while(1)
        mtx=map_option(mtx);

    for(int i=0; i<mtx.r; i++)
        free(mtx.map[i]);
    free(mtx.map);
    return 0;
}
