#include <iostream>
using namespace std;

int main() {
	long long int testcases,input,i,j,duplicate,duplicate1,flagship,sum,n;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>input;
		n=0;
		long long int *prime=new long long int[input];
		prime[0]=2;
		if(input==1)
		{
			cout<<0<<endl;
		}
		else
		{
			if(input==2)
			{
				cout<<prime[n]<<endl;
			}
			else if(input>2)
			{
				sum=2;
				for(j=3;j<=input;j++)
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
						sum=sum+prime[n];
					}
				}
			cout<<sum<<endl;
			}
		}
	}
				
						
					
						
					
				
			
		
	
	// your code goes here
	return 0;
}