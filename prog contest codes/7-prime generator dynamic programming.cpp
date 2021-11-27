#include <iostream>
using namespace std;

int main() {
	long long int testcases,input,i,j,n,duplicate,flagship,duplicate1;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>input;
		long long int *prime=new long long int[input];
		prime[0]=2;
		n=0;
		if(input==1)
		{
			cout<<prime[n]<<endl;
		}
		else
		{
			for(j=3;n<(input-1);j=j+2)
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
		cout<<prime[n]<<endl;
		}
		
		
	}
	// your code goes here
	return 0;
}