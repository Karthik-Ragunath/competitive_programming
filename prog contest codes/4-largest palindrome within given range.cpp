#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int ispalindrome(long long int num)
{
	stringstream ss;
	int length,l,flagship=1;
	string str;
	ss<<num;
	ss>>str;
	length=str.length();
	for(l=0;l<length;l++)
	{
		if(str[l]!=str[length-1-l])
		{
			flagship=0;
			break;
			
		}
	}
	if(flagship==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() {
	long long int number,numerical[1000000],n,length1,palindrome;
	int i,j,testcases,m,k,t;
	cin>>testcases;
	for(m=0;m<testcases;m++)
	{
		cin>>n;
		k=0;
		length1=0;
		palindrome=0;
		for(i=100;i<=999;i++ )
		{
			for(j=100;j<=999;j++)
			{
				number=i*j;
				if(ispalindrome(number)==1)
				{
					if(number<n)
					{
						numerical[k]=number;
						k++;
					}
				
				}
			}
		}
		length1=k;
		for(t=0;t<length1;t++)
		{
			if(numerical[t]>=palindrome)
			{
				palindrome=numerical[t];
			}
			
		}
		cout<<palindrome<<endl;
	}
	// your code goes here
	return 0;
}