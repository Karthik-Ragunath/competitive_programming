#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=(a); i<=(int)(b); i++)
#define REP(i, b) for(int i=0; i<(int)(b); i++)

using namespace std;
typedef unsigned long long ull;

struct point_t {
    short x, y;
    point_t() {}
    point_t(int x, int y) : x(x), y(y) {}
};

const int N = 2005;
int a[N][N], com[N][N];
int T = 0;
int m, n;

const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
point_t q[N*N];
int L, R;
int sz[N*N], setsz[N*N];
void BFS(int si, int sj) {
    if(com[si][sj]) return;

    L = R = 0;
    q[R++] = {si, sj}; com[si][sj] = ++T;
    int c = a[si][sj], cnt = 1;
    while(L < R) {
        const auto &p = q[L++];
        FOR(k,0,3) {
            int ni = p.x + di[k], nj = p.y + dj[k];
            if(1 <= ni && ni <= m && 1 <= nj && nj <= n &&
               !com[ni][nj] && a[ni][nj] == c) {
                    q[R++] = {ni, nj};
                    com[ni][nj] = T;
                    cnt++;
               }
        }
    }
    setsz[T] = sz[T] = cnt;
}

void print()
{
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
        	cout << com[i][j] << " ";
        }
        cout << endl;
    }
}

struct wall_t { int u, v; ull c; };
bool operator<(const wall_t &a, const wall_t &b) {
    return a.c < b.c;
}
wall_t wall[2*N*N]; int WL = 0;
ull get_c(int c1, int c2) {
    if(c1 < c2)
    {
        //cout << "c1: " << c1 << " c2: " << c2 << " c1 adjusted: " <<  (1ULL*c1 << 32) << " value: " << ((1ULL*c1 << 32) | c2) << endl;
        return (1ULL*c1 << 32) | c2;
    }
    else
    {
        //cout << "c1: " << c1 << " c2: " << c2 << " c2 adjusted: " <<  (1ULL*c2 << 32) << " value: " << ((1ULL*c2 << 32) | c1) << endl;
        return (1ULL*c2 << 32) | c1;
    }
}

void AddWall(int x1, int y1, int x2, int y2) {
    if(com[x1][y1] == com[x2][y2]) return;
    //cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << endl;
    wall[WL++] = {com[x1][y1], com[x2][y2], get_c(a[x1][y1], a[x2][y2])};
}

int p[N*N];
int findset(int i)
{
    return p[i] == i ? i : p[i] = findset(p[i]);
}
int join(int i, int j) {
    int u = findset(i), v = findset(j);
    if(u == v) return setsz[v];
    else {
        p[u] = v;
        return setsz[v] += setsz[u];
    }
}

void Reset(int q) {
    setsz[q] = sz[q];
    p[q] = q;
}
void Solve() {
    wall[WL].c = ULLONG_MAX;
    FOR(i,0,T) p[i] = i;

    int i = 0;
    ull rc = wall[0].c;
    cout << "Index: " << i << " U: " << wall[0].u << " V: " << wall[0].v << " C: " << wall[0].c << endl;
    int ans = 0;
    //cout << "Wall Size: " << WL << endl;
    FOR(j,1,WL) {
        cout << "Index: " << i << " U: " << wall[j].u << " V: " << wall[j].v << " C: " << wall[j].c << endl;
        if(wall[j].c != rc) {
        	cout << "New: " << j << endl;
            for(int k = i; k < j; k++)
            {
                //cout << "k: " << k << " U: " << wall[k].u << " V: " << wall[k].v << " ";
                ans = max(ans, join(wall[k].u, wall[k].v));
                cout << ans << endl;
            }
            for(int k = i; k < j; k++) {
                Reset(wall[k].u);
                Reset(wall[k].v);
            }
            rc = wall[j].c, i = j;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
    FOR(i,1,m) FOR(j,1,n) BFS(i, j);
    print();
    FOR(i,1,m) FOR(j,1,n) {
        if(i >= 2) AddWall(i-1, j, i, j);
        if(j >= 2) AddWall(i, j-1, i, j);
    }

    if(WL) {
        sort(wall, wall+WL);
        Solve();
    } else {
        cout << n*m;
    }

    return 0;
}
