#include <iostream>
using namespace std;

int greatestcommondivisor(int num1,int num2)
    {
    if(num2==0)
        {
        return num1;
        }
    else
        {
        while(num2>0)
            {
            int num3;
            num3=num2;
            num2=num1%num2;
              if(num2==0)
                {
                return num3;
                  break;
                }
            num1=num3;
                
            
            
            }
        }
    return 0;
    }
int main() {
    int testcases,n,i,gcd,j;
    cin>>testcases;
    while(testcases>0)
        {
        gcd=0;
        cin>>n;
        for(i=0;i<n;i++)
            {
            cin>>j;
            //cout<<gcd;
            gcd=greatestcommondivisor(gcd,j);
            }
            if(gcd==1)
                {
                cout<<"YES"<<endl;
                
                }
            else
                {
                cout<<"NO"<<endl;
                }
        testcases=testcases-1;
        }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}