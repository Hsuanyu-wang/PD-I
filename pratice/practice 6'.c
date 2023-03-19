#include<stdio.h>
#include<string.h>

//void popch(char a[], int n, int flag)
//{
//    for(int j=n;j<=flag;j++)
//    {
//        a[j]=a[j+1];
//    }
//}

void pop(float f[], char a[], int n, int flag)
{
    for(int j=n+1;j<=flag;j++)
    {
        f[j]=f[j+1];
    }
    for(int j=n;j<=flag;j++)
    {
        a[j]=a[j+1];
    }
}

int main(void)
{
    int i = 0,flag = 0;
    char l= '0',a[50];
    float num[50],sum = 0;
    for(i=1;i<50;i++)
    {
        a[i] = '0';
        num[i]=0;

    }
    for(i=1;i<50;i++)
    {
        flag = i;
        scanf("%f",&num[i]);
        if((l = getchar()) != '\n')
            a[i] = l;
        else
        {
//            printf("%d ",flag);
//            printf("%.2f ",num[i]);
//            printf("\\n");
            break;
        }
//        printf("%d ",flag);
//        printf("%.2f ",num[i]);
//        printf("%c \n",a[i]);
    }
    for(i=1;i<=flag;i++)
    {
        if(a[i] == '*')
        {
            num[i] *= num[i+1];
            pop(num,a,i,flag);
//            popch(a,i,flag);
//            popfl(num,i+1,flag);
            i--;
        }
        else if(a[i] == '/')
        {
            num[i] /= num[i+1];
            pop(num,a,i,flag);
//            popch(a,i,flag);
//            popfl(num,i+1,flag);
            i--;
        }
    }
    for(i=1;i<=flag;i++)
    {
        if(a[i] == '-')
        {
            num[i] -= num[i+1];
            pop(num,a,i,flag);
//            popch(a,i,flag);
//            popfl(num,i+1,flag);
            i--;
        }
    }
    for(i=1;i<=flag;i++)
    {
//        printf("%.2f ",num[i]);
        sum+=num[i];
    }
    printf("%.2f ",sum);
    return 0;
}
//1+2-3*4/5
