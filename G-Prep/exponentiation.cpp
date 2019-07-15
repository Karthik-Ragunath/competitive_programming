#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution 
{
	public:
    	double myPow(double x, long long int n) 
    	{
    		if(n == 0)
    		{
    			return 1;
    		}
        	if(n < 0)
        	{
        		x = 1 / x;
        		n = (-n);
        	}
        	double current_product = x;
        	double solution = 1;
        	for(long long int i = n; i > 0; i /= 2)
        	{
        		if(i % 2 == 1)
        		{
        			solution = solution * current_product;
        		}
        		current_product *= current_product;
        	}
        	return solution;
    	}
};

int main()
{
	double x, n;
	x = 2.00000;
	n = 10;
	Solution solution;
	double solution_val = solution.myPow(x, n);
	cout << solution_val << "\n";
	return 0;
}