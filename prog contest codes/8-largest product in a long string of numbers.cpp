#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int testcases,consdig,numofdig,l,i;
	long long int product,product1,realproduct,j;
	string number;
	stringstream ss;
	cin>>testcases;
	for(l=0;l<testcases;l++)
	{
		cin>>numofdig>>consdig;
		ss.clear();
		long long int *integer=new long long int[numofdig];
		cin>>number;
		j=0;
		product=1;
		product1=0;
		realproduct=0;
		for(i=0;i<numofdig;i++)
		{
			ss.clear();
			ss<<number[i];
			ss>>integer[i];
		}
		for(i=0;i<numofdig;i++)
		{
			if(integer[i]!=0)
			{
				j=j+1;
					//cout<<j<<endl;
			}
			else
			{
				j=0;
				product=1;
					//cout<<j<<endl;
				continue;
			}
			if(j<consdig)
			{
				product=product*integer[i];
				//	cout<<product<<endl;
			}
			if(j==consdig)
			{
				product=product*integer[i];
				product1=product;
				//	cout<<product<<endl;
			}
			if(j>consdig)
			{
				product=product/integer[i-consdig];
				product=product*integer[i];
				product1=product;
				//	cout<<product<<endl;
			}
			if(product1>realproduct)
			{
				realproduct=product1;
			}
			
		
		}
		cout<<realproduct<<endl;
	}
	// your code goes here
	return 0;
}