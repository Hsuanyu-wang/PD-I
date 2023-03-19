#include<stdio.h>
int main(void)
{
    float i,sum=0,num;
//    float sum,pro_num,lat_num;
    char amt1;//,amt2;
//    scanf("%f",&sum);
    scanf("%f",&num);
    sum = num;
    while((amt1=getchar()) != '\n')
    {
        scanf("%f",&num);

        if(amt1 == '+')
            sum+=num;
        else if(amt1 == '-')
            sum-=num;
        else if(amt1 == '*')
            sum*=num;
        else if(amt1 == '/')
        {
            if(num==0)
            {
                printf("error\n");
                break;
            }
            else
                sum/=num;
        }
    }
    printf("%.2f\n",sum);
    return 0;
}
