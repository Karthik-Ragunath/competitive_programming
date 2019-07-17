#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int length,k;
    string s1;
    int d,l,trace,d1,i;
    cin>>length;
    cin>>s1;
    cin>>k;
    l=k%26;
    for(i=0;i<length;i++)
        {
        d=s1[i];
        if((d>=65)&&(d<=90))
            {
            trace=d+l;
            if(trace<=90)
                {
                s1[i]=s1[i]+l;
                }
            if(trace>90)
                {
                d1=trace-90;
                s1[i]='A'+(d1-1);
                }
            
            }
          if((d>=97)&&(d<=122))
            {
            trace=d+l;
            if(trace<=122)
                {
                s1[i]=s1[i]+l;
                }
            if(trace>122)
                {
                d1=trace-122;
                s1[i]='a'+(d1-1);
                }
            
            }

        
        
        }
    cout<<s1;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
