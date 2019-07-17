#include <iostream>
using namespace std;
int main() {
    int lengthoffreeway,testcases,lanewidth[100000],j,k,l,i,min;
    cin>>lengthoffreeway>>testcases;
    for(i=0;i<lengthoffreeway;i++)
        {
        cin>>lanewidth[i];
        
        }
    for(i=0;i<testcases;i++)
        {
        cin>>j>>k;
        min=lanewidth[j];
        for(l=j;l<=k;l++)
            {
            if(lanewidth[l]<=min)
                {
                min=lanewidth[l];
                }
            }
            cout<<min<<endl;
        }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}