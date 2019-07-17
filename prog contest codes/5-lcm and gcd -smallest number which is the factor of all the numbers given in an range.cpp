#include <iostream>
using namespace std;
long long int gcd(long long int,long long int);
long long int lcm(long long int factor1,long long int factor2)
{
	long long int ans;
	ans=(factor1*factor2)/gcd(factor1,factor2);
	return ans;
}
/* finding gcd using euclidean algorithm*/ 
long long int gcd(long long int fac1,long long int fac2)
{
	long long int temp;
	while(fac2)
	{
		temp=fac2;
		fac2=fac1%fac2;
		fac1=temp;
	}
	return fac1;
	
}

int main() {
	long long int answer,firstfactor;;
	int testcases,i,input,j;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>input;
		answer=input;
		for(j=input;j>=2;j--)
		{
			firstfactor=j-1;
			answer=lcm(firstfactor,answer);
		}
		cout<<answer<<endl;
	}
	
	
	// your code goes here
	return 0;
}