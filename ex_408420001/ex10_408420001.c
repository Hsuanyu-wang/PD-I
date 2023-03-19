#include<stdio.h>
#include<string.h>

void print_array(int iteration,int array[],int length)
{
    if(iteration == 0)
    {
        printf("Stack is empty\n");
    }
    else if(iteration > length)
    {
        printf("Stack overflow\n");
    }
    else if(iteration < 0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        for(int i=0; i<iteration; i++)
            printf("->%d\n",array[i]);
    }
}

int main()
{
    int stack_size;
    int option;
    int pushed_item,popped_item;
    int i=0;
    int* array;
    printf("Enter the size of the stack :");
    scanf("%d",&stack_size);
    array = malloc(stack_size*sizeof(int));
    while(1)
    {
        printf("1.Push 2.Pop 3.Display 4.Exit:");
        scanf("%d",&option);
        if(option == 1)
        {
            printf("Enter the item to be pushed :");
            scanf("%d",&pushed_item);
            array[i]=pushed_item;
            i++;
            print_array(i,array,stack_size);
        }
        else if(option == 2)
        {
            i--;
            printf("Element %d has been popped from the stack\n",array[i]);
            array[i]=0;
            print_array(i,array,stack_size);
        }
        else if(option == 3)
        {
            print_array(i,array,stack_size);
        }
        else if(option == 4)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    free(array);
    return 0;
}
