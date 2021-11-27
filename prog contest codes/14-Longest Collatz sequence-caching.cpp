#include <iostream>
using namespace std;

int main() {
	long long int testcases,input,i,j,sequence,length,maxlength,number,k;
	long long int *cache=new long long int[50000002];
	for(i=0;i<50000002;i++)
	{
		cache[i]=-1;
	}
	cache[1]=1;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>input;
		maxlength=0;
		if(input==1)
		{
			cout<<cache[1]<<endl;
		}
		else
		{
			sequence=0;
			number=0;
			for(j=2;j<=input;j++)
			{
				sequence=j;
				k=0;
				while(sequence!=1 && sequence>=j)
				{
				
					k++;
					if(sequence%2==0)
					{
						sequence=sequence/2;
						//cout<<sequence<<endl;
					}
					else
					{
						sequence=sequence*3+1;
					}
				}
				cache[j]=k+cache[sequence];
				if(cache[j]>=maxlength)
				{
					maxlength=cache[j];;
					number=j;
				}
			
			}
			cout<<number<<endl;
		}
	}
	// your code goes here
	return 0;
}