#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int testcases,n,answer,i,sumofsquares,squareofsum,sum;
	cin>>testcases;
	for(i=0;i<testcases;i++)
	{
		cin>>n;
		sumofsquares=(n*(n+1)*(2*n+1))/6;
		sum=(n*(n+1))/2;
		squareofsum=pow(sum,2);
	//	cout<<sum<<endl<<squareofsum<<endl<<sumofsquares<<endl;
		answer=squareofsum-sumofsquares;
		cout<<answer<<endl;
		
	}
	// your code goes here
	return 0;
}