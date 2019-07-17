#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
    {
        int size,a[1000],i,j,pivotvalue,pivot,d,temp;
        cin>>size;
        for(i=0;i<size;i++)
            {
            cin>>a[i];
            }
        pivotvalue=a[0];
        pivot=0;
        for(i=1;i<size;i++)
            {
            if(a[i]<pivotvalue)
                {
                j=i;
                d=i-pivot;
                while(d>0)
                    {
                    temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                   // cout<<"i am here "<<a[j]<<endl;
                   /* cout<<"this is j "<<j<<endl;
                    cout<<"this is a[j-1] "<<a[j-1]<<endl;
                    cout<<"this is a[j] "<<a[j]<<endl;*/
                    j--;
                    d--;
                    }
                pivot=pivot+1;
                }
            }
        for(i=0;i<size;i++)
            {
            cout<<a[i]<<" ";
            }
    return 0;
    }
   
    