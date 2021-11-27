#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int limits,begin,end,num,flag,i,j,k,count,n,n1,testcases;
	cout<<"enter the max possible limit : "<<endl;
	cin>>limits;
	int *array=new int[limits];
	cin>>testcases;
	for(k=0;k<testcases;k++)
	{
		cout<<"testcase no: "<<k+1<<endl;
		count=0;
		cout<<"enter the beginning and ending limits"<<endl;
		cin>>begin>>end;
		num=sqrt(end);
		cout<<num<<endl;
		array[0]=1;
		array[1]=1;
		for(i=2;i<=num;i++)
		{
		
			for(j=i*i;j<=end;j=i*j)
			{
				cout<<j<<endl;
				array[j]=1;
			}
			
		}
		flag=0;
		for(i=begin;i<=end;i++)
		{
			//cout<<" i am in "<<endl;
			n=i;
			n1=n/2;
			for(j=0;j<n1;j++)
			{
				
				cout<<j<<" space " <<n-j<<endl;
				if(array[j]&&array[n-j])
				{
					flag=1;
					count=count+1;
					cout<<"the number "<<i<<" is a sum of powers "<<endl;
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
		cout<<"the number of possible sum of powers is "<<count<<endl;
		
	}
	// your code goes here
	return 0;
}