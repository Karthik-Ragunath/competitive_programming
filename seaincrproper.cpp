//IN THE NAME OF GOD
#include <bits/stdc++.h>

//all licenses protected for CODECHEF.
using namespace std;
#define ld long double
#define tll long long int
#define mp make_pair
#define maxn 1000110
#define ln 20
#define mod 1000000007
int arr[maxn],n,m;
vector<int> adj[maxn];
vector<pair<int,int>> query[maxn];
int nearest[maxn],lis[maxn],ans[maxn];
/**************************/
int bitt[maxn];
void update(int n,int index,int val)
{
    while (index <= n)
    {
       bitt[index]=max(val,bitt[index]);
       index += index & (-index);
       cout << "ending index:" << bitt[index] << endl;;
    }
}
int maxi(int index)
{
    int mas = 0;
	while (index>0)
    {
        mas=max(mas,bitt[index]);
        index -= index & (-index);
        cout << "createFenwickTree maxval: " << mas;
    }
    return mas;
}
/**************************/
void dfs(int node,int len){
	if(lis[node]<len){
		cout << "max val: " << lis[node] << endl;
		for(auto v:adj[node]){
			dfs(v,len+1);
		}
	}
	if(lis[node]<len){
		update(n,node,len);
		lis[node]=len;
		cout << "index: " << node << " maxx: " << lis[node] << endl;
	}
}
 
int main() {
	int tt;cin>>tt;
	while(tt--){
		bitt[0]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			bitt[i]=0;
		}
		int prev;
		for(int i=1;i<=n;i++){
			nearest[arr[i]]=i;
			prev=-1;
			for(int j=arr[i]-1;j>=1;j--){
				if(nearest[j]!=0 && nearest[j]>prev){
					adj[nearest[j]].push_back(i);
					prev=nearest[j];
					cout << "i: " << i << " prev: " << prev << endl;
				}
			}
		}
		for(int q=0;q<m;q++){
			int l,r;scanf("%d%d",&l,&r);
			query[l].push_back(mp(r,q));
		}
		for(int i=n;i>=1;i--){
			dfs(i,1);
			for(auto v:query[i]){
				ans[v.second]=maxi(v.first);
			}
		}
		for(int i=0;i<m;i++){
			printf("%d\n",ans[i]);
		}
		for(int i=0;i<=n;i++){
			nearest[arr[i]]=0;lis[i]=0;
			adj[i].clear();
			query[i].clear();
		}
	}
	return 0;
}        