#include<stdio.h>
int main(void)
{
    int i;
    float sum,pro_num,lat_num;
    char amt1,amt2;
    scanf("%f",&sum);
    while((amt1=getchar()) != '\n')
    {
        scanf("%f",&pro_num);
        amt2=getchar();

        if(amt2 == '\n')
        {
            if(amt1 == '+')
                sum+=pro_num;
            else if(amt1 == '-')
                sum-=pro_num;
            else if(amt1 == '*')
                sum*=pro_num;
            else if(amt1 == '/')
                sum/=pro_num;
            break;
        }
        else
        {
            scanf("%f",&lat_num);
            if((amt1 == '+' || amt1 =='-') && (amt2 == '*' || amt2 =='/'))
            {
                if(amt1 == '+')
                {
                    if(amt2 == '*')
                        sum+=(pro_num*lat_num);
                    else if(amt2 == '/')
                        sum+=(pro_num/lat_num);
                }
                else if(amt1 == '-')
                {
                    if(amt2 == '*')
                        sum-=(pro_num*lat_num);
                    else if(amt2 == '/')
                        sum-=(pro_num/lat_num);
                }
            }
            else if((amt1 == '+' || amt1 =='-') && (amt2 == '+' || amt2 =='-'))
            {
                if(amt1 == '+')
                {
                    if(amt2 == '+')
                        sum+=(pro_num+lat_num);
                    else if(amt2 == '-')
                        sum+=(pro_num-lat_num);
                }
                else if(amt1 == '-')
                {
                    if(amt2 == '+')
                        sum-=(pro_num-lat_num);
                    else if(amt2 == '-')
                        sum-=(pro_num+lat_num);
                }
            }
            else if((amt1 == '*' || amt1 =='/') && (amt2 == '*' || amt2 =='/'))
            {
                if(amt1 == '*')
                {
                    if(amt2 == '*')
                        sum*=(pro_num*lat_num);
                    else if(amt2 == '/')
                        sum/=(pro_num/lat_num);
                }
                else if(amt1 == '/')
                {
                    if(amt2 == '*')
                        sum/=(pro_num/lat_num);
                    else if(amt2 == '/')
                        sum/=(pro_num*lat_num);
                }
            }
            else if((amt1 == '*' || amt1 =='/') && (amt2 == '+' || amt2 =='-'))
            {
                if(amt1 == '*')
                {
                    if(amt2 == '+')
                        sum=sum*pro_num+lat_num;
                    else if(amt2 == '-')
                        sum=sum*pro_num-lat_num;
                }
                else if(amt1 == '/')
                {
                    if(amt2 == '+')
                        sum=sum/pro_num+lat_num;
                    else if(amt2 == '-')
                        sum=sum/pro_num-lat_num;
                }
            }
        }
    }
    printf("%.2f\n",sum);
    return 0;
}
