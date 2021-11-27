#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int testcases,consdig,numofdig,l,i;
	long long int product,product1;
	string number;
	stringstream ss;
	cin>>testcases;
	for(l=0;l<testcases;l++)
	{
		cin>>numofdig>>consdig;
		ss.clear();
		long long int *integer=new long long int[numofdig];
		cin>>number;
		product=1;
		for(i=0;i<numofdig;i++)
		{
			ss.clear();
			ss<<number[i];
			ss>>integer[i];
		}
		for(i=0;i<numofdig;i++)
		{
			if(i>4)
			{
				if(i==5)
				{
					product1=product;
				}
				if(integer[i-5]==0)
				{
					continue;
				}
				else
				{
					product=product/integer[i-5];
				}
			}
			else
			{
				product=product*integer[i];
				continue;
			}
			if(integer[i]!=0)
			{
				product=product	
			}
		
		}
	}
	// your code goes here
	return 0;
}