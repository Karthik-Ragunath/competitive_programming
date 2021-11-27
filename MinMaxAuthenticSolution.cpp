/*
    User :- rajankur
    IDE  :- Offline Linux terminal
    Codechef July Challenge
    Problem - No Minimum No Maximum Problem  Code: NMNMX
    Reference :- GeeksforGeeks
*/
#include<bits/stdc++.h>
using namespace std;
# define ll long long int
# define mod 1000000007
ll power(ll x, ll y, ll p)
{
    ll res = 1;
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
ll modInverse(ll n, ll p)
{
return power(n, p-2, p);
}
ll nCrModPFermat(ll n, ll r, ll p,ll fac[])
{
if (r==0)
  return 1;
return (fac[n]* modInverse(fac[r], p) % p *
        modInverse(fac[n-r], p) % p) % p;
}
ll nCrModpDP(ll n, ll r, ll p)
{
ll C[r+1];
memset(C, 0, sizeof(C));
C[0] = 1;
for (ll i = 1; i <= n; i++)
{
    for (ll j = min(i, r); j > 0; j--)
        C[j] = (C[j] + C[j-1])%p;
}
return C[r];
}
ll nCrModpLucas(ll n, ll r, ll p)
{
if (r==0)
    return 1;
ll ni = n%p, ri = r%p;
return (nCrModpLucas(n/p, r/p, p) *
        nCrModpDP(ni, ri, p)) % p;
}
int main()
{
            #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
    ll i,j,k,m,n,p,t;
ll r=(mod-1)/2,q=mod-1,e=2,v,w;
cin>>t;
long long int  fac[6001];
fac[0] = 1;
for (long long int  i=1 ; i<=5002; i++)
fac[i] = fac[i-1]*i%r;
    while(t--)
    {
        cin>>n;
        cin>>k;
        ll arr[n],dup[n],pos,a=n-1,b=k-1,c,d=mod-1,res=1,s,ans=1,out=1,val=1,sum;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n,greater<ll>());
    s=nCrModPFermat(a,b,r,fac);
//cout<<s<<" A "<<a<<" B "<<b<<" R "<<r<<endl;
    if(b&(a-b))
        v=0;
    else
        v=1;
    w=0;
    if(a-b==0)
        v=1;
    ll y=250000002;
    w=(w+s*e*y)%q;
    w=(w+v*r)%q;
    //cout<<w<<" "<<v<<" "<<a-b<<" "<<b<<endl;
    ll min_count=0,max_count=0,tot=0,cnt=0,min_count1=0,max_count1=0,min_count2=0,max_count2=0;
    ll sum1,sum2;
    b=k-1;
        for(i=0;i<n;i++)
        {
        min_count=0,max_count=0;
        if(i<k-1)
            min_count=0;
        else
        {
            a=i;
            min_count1=nCrModPFermat(a,b,r,fac);
            if(b&(a-b))
                min_count2=0;
            else
                min_count2=1;
            if(a-b==0)
                min_count2=1;
            min_count=(min_count+min_count1*e*y)%q;
            min_count=(min_count+min_count2*r)%q;
        }
        if((n-i-1)<k-1)
            max_count=0;
        else
        {
            a=n-i-1;
            max_count1=nCrModPFermat(a,b,r,fac);
            //cout<<max_count1<<" D "<<endl;
            a=n-i-1;
            if(b&(a-b))
                max_count2=0;
            else
                max_count2=1;
            if(a-b==0)
                max_count2=1;
            //cout<<max_count2<<" E "<<endl;
            max_count=(max_count+max_count1*e*y)%q;
            //cout<<max_count<<endl;
            max_count=(max_count+max_count2*r)%q;
        }
        //cout<<"MAX = "<<max_count<<" MIN = "<<min_count<<"  "<<arr[i]<<endl;
        ans=(max_count+min_count)%q;
    //cout<<ans<<endl;
    ans=ans*-1;
    //cout<<ans<<endl;
    ans=((ans % q) + q) % q;
        ans=(w+ans)%q;
    //cout<<"MAX = "<<max_count<<" MIN = "<<min_count<<"  "<<ans<<"  =  "<<arr[i]<<endl;
        tot=power(arr[i],ans,mod);
        out=(out*tot)%mod;
        }
            cout<<out<<endl;
    }
}   
