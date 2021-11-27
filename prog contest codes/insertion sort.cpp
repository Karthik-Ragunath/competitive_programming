#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
int main()
    {
    int size,i,j,a[1000],temp,k;
    cin>>size;
    for(i=0;i<size;i++)
        {
        cin>>a[i];
        }
    for(i=1;i<size;i++)
        {
        for(j=0;j<=i-1;j++)
            {
            if(a[j]>a[i])
                {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
                
                }
            }
        for(k=0;k<size;k++)
            {
            cout<<a[k]<<" ";
            }
        cout<<endl;
        }
    return 0;
    
    }