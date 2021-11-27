/*fibonacci sum of even terms in a series within a given range of n natural numbers */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int testcases,i,n=1,sum=2,duplicate;
    cin>>testcases;
    long long int *limits=new long long int[testcases];
    long long int fibo[1000000];
    fibo[0]=0;
    fibo[1]=2;
    for(i=0;i<testcases;i++)
    {
        cin>>limits[i];
        sum=2;
        n=1;
        
        while(fibo[n]<=limits[i])
            {
            fibo[n+1]=4*fibo[n]+fibo[n-1];
            
                if(fibo[n+1]<=limits[i])
                    {
                    sum=sum+fibo[n+1];
                    }
            
                    n=n+1;
            }
            cout<<sum<<endl;
     }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
