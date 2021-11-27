#include<stdio.h>
int calculate(int i,int *sum)
{
    i=i+1;
    printf("%d\n",i);
    *sum=*sum+i;
    printf("%d\n",*sum);
    if(i==4)
    {
        return 0;
    }
    else
    {
        calculate(i,sum);
    }
    *sum=*sum+i;
    printf("%d\n",*sum);
    printf("%d\n",i);
    return 0;
}
int main()
{
    int i=0,sum1=0;
    int *sum=&sum1;
    calculate(i,sum);
    printf("%d\n",sum1);
}

Output:
1
1
2
3
3
6
4
10
13
3
15
2
16
1
16