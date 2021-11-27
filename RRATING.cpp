#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cassert>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 
int main(){
  int N, mode, x;
  int sz;
  priority_queue<int> up, down;
 
  ( scanf("%d",&N)==1 );
  (1 <= N && N <= 100000);
  
  sz = 0;
  while(N--){
    ( scanf("%d",&mode)==1 );
    (mode == 1 || mode == 2);
    if(mode == 1){
      ( scanf("%d",&x)==1 );
      (1 <= x && x <= 1000000000);
      if(up.size() == 0 || x >= -up.top()) up.push(-x);
      else                                 down.push(x);
      sz++;
 
      while(up.size() < sz/3){
        x = down.top(); down.pop();
        up.push(-x);
      }
      while(up.size() > sz/3){
        x = -up.top(); up.pop();
        down.push(x);
      }
    } else {
      if(sz / 3 == 0) puts("No reviews yet");
      else            printf("%d\n", -up.top());
    }
  }
 
  return 0;
}
 
