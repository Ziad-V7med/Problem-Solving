#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    int n , m; cin >> n >> m;
    vector<int> h(n + 1) , freq(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int i = 1; i <= m; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        freq[u] += (h[u] > h[v]);
        freq[v] += (h[v] > h[u]);
    }
    
    int good = 0;

    for (int i = 1; i <= n; i++) 
        if (freq[i] == adj[i].size())
            good++;

    cout << good << '\n';
   
}