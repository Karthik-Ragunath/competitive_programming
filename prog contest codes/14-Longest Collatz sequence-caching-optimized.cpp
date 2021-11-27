#include <iostream>
using namespace std;

int main() {
	long long int testcases,input,i,j,sequence,length,maxlength,number,k;
	long long int *cache=new long long int[5000002];
	cache[1]=1;
	for(i=2;i<=5000000;i++)
	{
		sequence=i;
		k=0;
		while(sequence!=1 && sequence>=i)
		{
			k++;
			if(sequence%2==0)
			{
				sequence=sequence/2;
			}
			else
			{
				sequence=sequence*3+1;
			}
		}
		cache[i]=k+cache[sequence];	
	}
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>input;
		maxlength=0;
		for(j=1;j<=input;j++)
		{
			if(cache[j]>=maxlength)
			{
				maxlength=cache[j];
				number=j;
			}
		}
		cout<<number<<endl;
	}
	// your code goes here
	return 0;
}