#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll n;
        cin >> n;
        vector< vector< ll > > trie_graph;
        vector< ll > visits(1, 0);
        vector< ll > parent(1, -1);
        trie_graph.emplace_back(26, -1);
        for(ll i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            ll current_size = 0;
            for(auto iter = t.rbegin(); iter != t.rend(); iter++)
            {
                ll val = (ll)(*iter - 'A');
                if(trie_graph[current_size][val] == -1)
                {
                    trie_graph[current_size][val] = trie_graph.size();
                    visits.push_back(0);
                    parent.push_back(current_size);
                    trie_graph.emplace_back(26, -1);
                }
                current_size = trie_graph[current_size][val];
                visits[current_size] += 1;
            }
        }
        ll answer = 0;
        for(ll i = trie_graph.size() - 1; i >= 0; i--)
        {
            if(visits[i] < 2)
            {
                continue;
            }
            answer += 1;
            ll v = i;
            while(v != -1)
            {
                visits[v] -= 2;
                v = parent[v];
            }
        }
        cout << "Case #" << (k + 1) << ": " << 2 * answer << endl;
    }
    return 0;
}