#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int prime(long long int n)
{	
	
        int k,l;
        if(n==2)
        {
        	return 1;
        }
        else
        {
			for(k=2;k<n;k++)
				{
					if(n%k==0)
					{
						
						return 0;
						
					}
				}
			return 1;
        }
}


int main() {
    int testcase,i,j,flagship;
    long long int number,num,m,primefactor,primefactor1,primefactor2,fac;
    cin>>testcase;
    for(i=0;i<testcase;i++)
        {
            cin>>number;
            flagship=1;
            primefactor=0;
            while((number%2==0)&&(number>2))
            {
           		number=number/2;
            }
            num=(long long int)sqrt(number);
            for(m=2;m<=num;m++)
                {
                    j=prime(m);
                    if(j==1)
                        {
                        
                            if(number%m==0)
                                {
                                	flagship=0;
                                    fac=number/m;
                                    if(prime(fac)==1)
                                    {
                                    	primefactor1=fac;
                                    	primefactor2=m;
                                    	if(primefactor1>primefactor2)
                                    	{
                                    		if(primefactor1>=primefactor2)
                                    		{
                                    			primefactor=primefactor1;
                                    			continue;
                                    		}
                                    	}
                                    	else if(primefactor2>primefactor1)
                                    	{
                                    		if(primefactor2>primefactor1)
                                    		{
                                    			primefactor=primefactor2;
                                    			continue;
                                    		}
                                    	}
                                    	
                                    }
                                    if(m>primefactor)
                                    {
                                    	primefactor=m;
                                    }
                                }
                            
                        }
                }
            if(flagship==0)
            {
            	cout<<primefactor<<endl;
            }
            else if(flagship==1)
            {
            	cout<<number<<endl;
            	
            	
            }
            
        }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

