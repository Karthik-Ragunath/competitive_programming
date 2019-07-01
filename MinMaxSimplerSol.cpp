#include<bits/stdc++.h>
using namespace std;
long long dp[5001][5001];
long long m=1000000007;

long long power(long long x, long long y,long long p)
{
    long long res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

long long modInv(long long a, long long m1)
{
    return power(a, m1-2, m1);
}


void dpfill()
{
	for(long long i=0;i<=5000;i++)
	{
		for(long long j=0;j<=min(i,5000ll);j++)
		{
			if (j == 0 || j == i)
			dp[i][j]=1;
			else
                dp[i][j] = ((dp[i-1][j-1] )%(m-1)+ (dp[i-1][j])%(m-1))%(m-1);

			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
}
int main()
{
	long long t; cin>>t;

	dpfill();
	while(t--)
	{
		long long n,k; cin>>n>>k;
		vector<long long> v(n);
		for(long long i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		long long ans=1;
		for(long long i=1;i<n-1;i++)
		{
			long long y=0;
			for(long long j=1;j<k-1;j++)
			{
				y+=((dp[i][j]*dp[n-i-1][k-j-1])%(m-1));
			}
			ans*=(power(v[i],y,m)%m);
			ans%=m;
		}
		cout<<ans<<endl;

	}
} 
