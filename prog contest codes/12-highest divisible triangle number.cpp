#include <iostream>
using namespace std;
long long int numberofdivisors(long long int number,long long int prime[] )
{
	long long int nod,exponent,reminder,i;
	reminder=number;
	nod=1;
	
	for(i=0;i<500;i++)
	{
		if(reminder==1)
		{
			return nod;
		}
		if(prime[i]*prime[i]>reminder)
		{
			nod=nod*2;
			return nod;
		}
		exponent=1;
		while(reminder%prime[i]==0)
		{
			exponent++;
			reminder=reminder/prime[i];
		}
		nod=nod*exponent;
		
	}
	return nod;
}
int main() {
	long long int i,j,n,duplicate,duplicate1,flagship,testcases,k,noofdivisors,triangle,length;
	length=700;
	long long int *prime=new long long int[length];
	long long int ret;
	prime[0]=2;
	for(j=3;n<500;j++)
	{
		duplicate=n;
		duplicate1=duplicate+1;
		flagship=1;
		while(duplicate1--)
		{
			if(j%prime[duplicate]==0)
			{
				flagship=0;
				break;
			}
			duplicate--;
		}
		if(flagship==1)
		{
			n++;
			prime[n]=j;
		}
	}
	/*for(i=0;i<10;i++)
	{
		cout<<prime[i]<<endl;
	}*/
	cin>>testcases;
	for(k=0;k<testcases;k++)
	{
		cin>>noofdivisors;
		for(i=1;;i++)
		{
			triangle=(i*(i+1))/2;
			//cout<<triangle<<endl;
			ret=numberofdivisors(triangle,prime);
			if(ret>noofdivisors)
			{
				cout<<triangle<<endl;
				break;
			}
		}
		
	}
	
	// your code goes here
	return 0;
}