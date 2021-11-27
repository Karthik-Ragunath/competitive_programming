#include<stdio.h>
int calculate(int i,int sum)
{
    i=i+1;
    printf("%d\n",i);
    sum=sum+i;
    printf("%d\n",sum);
    if(i==4)
    {
        return sum;
    }
    else
    {
        calculate(i,sum);
    }
    sum=sum+i;
    printf("%d\n",sum);
    printf("%d\n",i);
    return sum;
}
int main()
{
    int i=0,sum=0;
    int ans;
    ans=calculate(i,sum);
    return o;
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
9
3
5
2
2
1

Comment : "Sum not get returned to different levels, it gets banished "