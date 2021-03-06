#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cmath>
#include<cstring>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll read_int(ll mn, ll mx, char next){
  int c, fg = 1, res = 0;
  c=getchar();
  if(c=='-') fg = -1, c = getchar();
  assert('0'<=c && c<='9');
  res = c - '0';
  for(;;){
    c = getchar();
    if(c==' ' && next=='\n') continue;
    if(c=='\r' && next=='\n') continue;
    if(c==next) break;
    assert(res!=0);
    assert('0'<=c && c<='9');
    res = res * 10 + (c - '0');
  }
  res *= fg;
  assert(mn<=res && res<=mx);
  return res;
}

void read_int_arr(int n, int res[], ll mn, ll mx){
  int i;
  rep(i,n-1) res[i] = read_int(mn, mx, ' ');
  res[n-1] = read_int(mn, mx, '\n');
}


#define M 747474747
int N, D;
int p[6666][5];

// return distance^2 between points i and j
ll dist(int i, int j){
  int k; ll res = 0, diff;
  rep(k,D){
    diff = p[i][k] - p[j][k];
    res += diff * diff;
  }
  return res;
}

int main(){
  int T, Nsum = 0;
  
  int i, j, k;
  ll res;
  int visited[6666];
  ll mxdist[6666];
  ll mx; int ind;

  T = read_int(1, 6666, '\n');
  while(T--){
    N = read_int(1, 6666, ' ');
    D = read_int(1, 5, '\n');
    rep(i,N) read_int_arr(D, p[i], -100000000, 100000000);

    Nsum += N;
    assert(Nsum <= 6666);

    // prim with naive implimentation
    res = 1;
    rep(i,N) visited[i] = 0, mxdist[i] = 0;
    visited[0] = 1;
    rep(i,N) if(!visited[i]) mxdist[i] = max(mxdist[i], dist(0,i));
    for(;;){
      ind = -1; mx = 0;
      rep(i,N) if(!visited[i] && mx < mxdist[i]) ind = i, mx = mxdist[i];
      if(mx==0) break;
      res = (res * (mx%M)) % M;
      
      visited[ind] = 1;
      rep(i,N) if(!visited[i]) mxdist[i] = max(mxdist[i], dist(ind,i));
    }
    
    printf("%d\n",(int)res);
  }
  
  assert( scanf("%*c")==EOF );
  return 0;
}
