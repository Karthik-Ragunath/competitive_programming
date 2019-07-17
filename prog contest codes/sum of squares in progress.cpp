#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int limits,begin,end,testcases,num,flag,i,j,count=0,n,n1;
	cout<<"enter the max possible limit : "<<endl;
	cin>>limits;
	int *array=new int[limits];
	cout<<"enter the number of testcases : "<<endl;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cout<<"enter the beginning and ending limits"<<endl;
		cin>>begin>>end;
		num=sqrt(end);
		array[0]=1;
		array[1]=1;
		for(i=2;i<=num;i++)
		{
			if(array[i]==1)
			{
				continue;
			}
			for(j=i*i;j<=end;j=i*i)
			{
				array[j]=1;
			}
			
		}
		flag=0;
		for(i=begin;i<=end;i++)
		{
			n=i;
			n1=n/2;
			for(j=0;i<n1;i++)
			{
				if(array[j]&&array[n1-j])
				{
					flag=1;
					count=count+1;
					cout<<"the number "<<i<<" is a sum of squares "<<sqrt(j)<<" and "<<sqrt(n1-j)<<endl;
					break;
				}
				else
				{
					flag=0;
				}
			}
			if(flag==0)
			{
				cout<<"the number "<<i<<" cannot be expressed as a possible square of two integers "<<endl;
				
			}
			
		}
		
	}
	// your code goes here
	return 0;
}