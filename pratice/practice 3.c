#include<stdio.h>
#include<math.h>
int main()
{
    double a,b;
    scanf("(%lf",&a);
    scanf(" ,%lf)",&b);
if(a>0)
{
    if(b>0)
    printf("(%lf, %lf) is in Quadrant I\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else if(b==0)
    printf("(%lf, %lf) is on the x-axis\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else
    printf("(%lf, %lf) is in Quadrant IIII\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
}
else if(a==0)
{
     if(b>0)
    printf("(%lf, %lf) is on the y-axis\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else if(b==0)
    printf("(%lf, %lf) is at the origin(0, 0)\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else
    printf("(%lf, %lf) is on the y-axis\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
}
else
{
     if(b>0)
    printf("(%lf, %lf) is in Quadrant II\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else if(b==0)
    printf("(%lf, %lf) is on the x-axis\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
    else
    printf("(%lf, %lf) is in Quadrant III\nThe value of squared distance is %lf",a ,b ,a*a+b*b);
}
    return 0;
}
