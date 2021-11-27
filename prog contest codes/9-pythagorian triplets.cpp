#include <iostream>
using namespace std;

int main() {
	long long int testcases,sum,product,realproduct,i,a,b,c,flagship;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>sum;
		flagship=0;
		product=0;
		realproduct=0;
		for(a=1;a<sum/3;a++)
		{
			for(b=1;b<sum/2;b++)
			{
				c=sum-a-b;
				if(a*a+b*b=c*c)
				{
					flagship=1;
					product=a*b*c;
					if(product>realproduct)
					{
						realproduct=product;
					}
				}
				
			}
		}
		if(flagship==1)
		{
			cout<<realproduct<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
		
		
	}
	// your code goes here
	return 0;
}