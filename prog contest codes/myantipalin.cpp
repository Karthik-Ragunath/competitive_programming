#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int k=1000000007;
int pow(int a,int b)
    {
    int v,x;
    if(b==0)
        {
        return 1;
        }
    if(b%2)
        {
        x=1LL*pow(a,b-1)*a%k;
        return x;
        }
    v=1LL*pow(a,b/2);
    return v*v%k;
    }


int main() {
    int answer,testcases,n,m,i=1;
    cin>>testcases;
    while(testcases--)
        {
           cin>>n>>m;
        if(n==1)
            {
            cout<<i<<endl;
            continue;
            }
        answer=1LL*m*(m-1);
        answer=1LL*answer*pow(m-2,n-2)%k;
        cout<<answer<<endl;
       }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
