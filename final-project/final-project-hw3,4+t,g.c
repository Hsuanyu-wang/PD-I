#include<stdio.h>
#include<stdlib.h>
//declare structure type
struct MTX
{
    int** map;
    int r,c;
    int pr,pc;
    int b,s;
};
//declare function
struct MTX create_map();
void print_map();
void setup_village();
void setup_monster();
//=======new
void setup_gun();
void setup_trap();
//======new
struct MTX setup_player();
int check_boundary();
int check_availability();
struct MTX check_move();
struct MTX go_up();
struct MTX go_down();
struct MTX go_left();
struct MTX go_right();
struct MTX move_option();
struct MTX map_option();
void free_memory();
struct MTX village_do();

struct MTX fight_monster();
void go_adventure();
//0:.(space) 1:village 2:monster 3:player 4:gun 5:trap

int main(void)
{
    struct MTX mtx;
    mtx=create_map();
    setup_village(mtx);
    setup_monster(mtx);
    setup_gun(mtx);
    setup_trap(mtx);
    print_map(mtx);
    while(1)
        mtx=map_option(mtx);
    free_memory(mtx);
    return 0;
}

struct MTX create_map(void)
{
    struct MTX m;
    int x=0,y=0;
    //map
    printf("Input the number of row and column for the map(at least 2*3 or 3*2):\n");
    scanf("%d %d",&x,&y);
    m.r=x;
    m.c=y;
    m.b=10;
    m.s=2;
//    m.pr=-1;
//    m.pc=-1;
    //set matrix
    m.map=malloc(sizeof(int*)*x);
    for(int i=0; i<x; i++)
    {
        m.map[i]=malloc(sizeof(int)*y);
    }
    //initialize
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            m.map[i][j]='.';
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
            if(m.map[i][j]>0 && m.map[i][j]<=(m.r%10+m.r/10))
                printf("m%d  ",m.map[i][j]);
            else
                printf("%c   ",m.map[i][j]);
        }
        printf("\n\n");
    }
    printf("=== MAP ===\n");
}
void setup_village(struct MTX m)
{
    int vx=0,vy=0;
    while(1)
    {
        printf("Input the row and column for the village location:\n");
        scanf("%d %d",&vx,&vy);
        if(check_boundary(m,vx,vy))
        {
            m.map[vx][vy]='v';
            break;
        }
    }
}
void setup_monster(struct MTX m)
{
//    int n=0
    int i=1;
//    n=m.r%10+m.r/10;
    int mx=0,my=0;
    while(i<=(m.r%10+m.r/10))
    {
        printf("You need to assign location for %d monsters in total\n",m.r%10+m.r/10);
        printf("Input the row and column for monster %d:\n",i);
        scanf("%d %d",&mx,&my);
        if(check_boundary(m,mx,my) && check_availability(m,mx,my))
        {
            m.map[mx][my]=i;
            i++;
        }
    }
}
//=========================//
void setup_gun(struct MTX m)
{
    int gx=0,gy=0;
    while(1)
    {
        printf("Input the row and column for the gun location:\n");
        scanf("%d %d",&gx,&gy);
        if(check_boundary(m,gx,gy) && check_availability(m,gx,gy))
        {
            m.map[gx][gy]='g';
            break;
        }
    }
}
void setup_trap(struct MTX m)
{
    int tx=0,ty=0;
    while(1)
    {
        printf("Input the row and column for the trap location:\n");
        scanf("%d %d",&tx,&ty);
        if(check_boundary(m,tx,ty) && check_availability(m,tx,ty))
        {
            m.map[tx][ty]='t';
            break;
        }
    }
}
//==============================//
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
            m.map[px][py]='p';
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
        return 1;
}
int check_availability(struct MTX m,int x,int y)
{
    if(m.map[x][y] != '.')
    {
        printf("the location is occupied\n");
        return 0;
    }
    else
        return 1;
}
struct MTX check_move(struct MTX m,int x,int y,int move)
{
//    if(m.map[m.pr][m.pc] != 0)
    if(m.map[x][y] == 'v')
    {
        //int b=10,s=2;
        int v,f=0;
        printf("You have %d blood and %d strength.\n",m.b,m.s);
        printf("Do you want to go to our village first (1: Yes; 0: No)?\n");
        scanf("%d",&v);
        if(v==1)
        {
            while(1)
                m=village_do(f,m);
        }
        else
            printf("okay, move on\n");
    }
    else if(m.map[x][y]>0 && m.map[x][y]<=(m.r%10+m.r/10))
    {
        for(int i=1; i<=(m.r%10+m.r/10); i++)
            if(m.map[x][y] == i)
            {
                m=fight_monster(m,i);
            }
    }
    else if(m.map[x][y] == 'g' || m.map[x][y] == 't')
    {
        if(m.map[x][y] == 'g')
        {
        printf("you picked up a gun, strength + 1\n");
        printf("You have %d blood and %d strength.\n",m.b,++m.s);
        }
        else if(m.map[x][y] == 't')
        {
            printf("you were damaged by a trap, blood - 1\n");
            printf("You have %d blood and %d strength.\n",--m.b,m.s);
        }
        m.map[x][y]='p';
        switch(move)
        {
            case 0:
                m.map[x+1][y]='.';
                m.pr--;
                break;
            case 1:
                m.map[x-1][y]='.';
                m.pr++;
                break;
            case 2:
                m.map[x][y+1]='.';
                m.pc--;
                break;
            case 3:
                m.map[x][y-1]='.';
                m.pc++;
                break;
            default:
                break;
        }
        print_map(m);
    }
    else
        printf("you can't go there\n");
        return m;
//    else if(m.map[x][y] == 2)

}
//movement definition
// up=0,down=1,left= 2,right=3
struct MTX go_up(struct MTX m)
{
    int x=m.pr,y=m.pc;
    if((x-1) < 0 || m.map[x-1][y] != '.')
        m=check_move(m,x-1,y,0);
    else if(m.map[x-1][y] == '.')
    {
        m.pr--;
        m.map[x-1][y] = 'p',m.map[x][y] = '.';
        print_map(m);
    }
    return m;
}
struct MTX go_down(struct MTX m)
{
    int x=m.pr,y=m.pc,bx=m.r,by=m.c;
    if((x+1) >= bx || m.map[x+1][y] != '.')
        m=check_move(m,x+1,y,1);
    else //if(m.map[x+1][y] == '.')
    {
        m.pr++,m.map[x+1][y] = 'p',m.map[x][y] = '.',print_map(m);
    }
    return m;
}
struct MTX go_left(struct MTX m)
{
    int x=m.pr,y=m.pc;
    if((y-1) < 0 || m.map[x][y-1] != '.')
        m=check_move(m,x,y-1,2);
    else //if((y-1) >= 0 && m.map[x][y-1] == '.')
    {
        m.pc--,m.map[x][y-1] = 'p',m.map[x][y] = '.',print_map(m);
    }
    return m;
}
struct MTX go_right(struct MTX m)
{
    int x=m.pr,y=m.pc,bx=m.r,by=m.c;
    if(((y+1) >= by) || (m.map[x][y+1] != '.'))
        m=check_move(m,x,y+1,3);
    else
    {
        m.pc++;
        m.map[x][y+1] = 'p';
        m.map[x][y] = '.';
        print_map(m);
    }
    return m;
}
//option definition
struct MTX move_option(struct MTX m)
{
    int slct_pen;
    printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
    scanf("%d",&slct_pen);
    if(slct_pen == 1)
        m=go_up(m);
    else if(slct_pen == 2)
        m=go_down(m);
    else if(slct_pen == 3)
        m=go_right(m);
    else if(slct_pen == 4)
        m=go_left(m);
    else if(slct_pen == 5)
        exit(0);
    else
        printf("move option error\n");
    return m;
}
struct MTX map_option(struct MTX m)
{
    int slct_eth;
    printf("[1] Create a new map [2] Start travel the map: ");
    scanf("%d",&slct_eth);
    //new map
    if(slct_eth == 1)
    {
        m=create_map(),setup_village(m),setup_monster(m),setup_gun(m),setup_trap(m),print_map(m);
    }
    //travel
    else if(slct_eth == 2)
    {
        m=setup_player(m);
        print_map(m);
        printf("Welcome, Adventurer!\n");
        printf("You have %d blood and %d strength.\n",m.b,m.s);
        while(1)
            m=move_option(m);
    }
    else
    {
        printf("map option error\n"),exit(0);
    }
    return m;
}
void free_memory(struct MTX m)
{
    for(int i=0; i<m.r; i++)
        free(m.map[i]);
    free(m.map);
}
struct MTX village_do(int f,struct MTX m)
{
    int d;
    printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village):");
    scanf("%d",&d);
    if(d == 1 && f == 0)
    {
        m.s++;
        printf("Nice sword! Now you have %d strength!\n",m.s);
        f=1;
    }
    else if(d == 1 && f == 1 )
    {
        printf("You already brought a sword.\n");
    }
    else if(d == 2  && m.b<10)
    {
        printf("Nice beer! Now you have %d blood!\n",++m.b);
    }
    else if(d == 2 && m.b>=10)
    {
        printf("Your blood is full. You don't need a beer.\n");
    }
    else if (d == 3)
    {
        printf("You are welcome to come back anytime!\n");
        m=move_option(m);
    }
    else
        printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
    return m;
}
struct MTX fight_monster(struct MTX m,int mn)
{
    printf("You have %d blood and %d strength.\n",m.b,m.s);
    printf("You are fighting Monster %d!\n",mn);
    if(m.s>mn)
    {
        printf("You win\n");
        m.s++;
    }
    else if(m.s<=mn)
    {
        printf("You Lose\n");
        m.b-=mn;
    }
    go_adventure(m.b);
    return m;
}
void go_adventure(int b)
{
    int g;
    printf("Do you want to go on your adventure (1:Yes;0: No):");
    scanf("%d",&g);
    if(g==0)
    {
        printf("We will miss you. Bye!\n");
        exit(0);
    }
    else if(b<=0)
    {
        printf("You Dead. Bye!\n");
        exit(0);
    }
}
