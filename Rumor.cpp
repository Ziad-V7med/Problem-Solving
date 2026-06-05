#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m;

vector<vector<int>> adj;
vector<int> gold;
vector<bool> vis;

int DFS (int u) {
    vis[u] = true;
    int mn = gold[u];

    for (auto v : adj[u])
        if (!vis[v]) {
            mn = min(mn , DFS(v));
        }

    return mn;
}

signed main () {
    matador
    cin >> n >> m;
    adj.assign(n + 1 , {});
    gold.assign(n + 1 , 0);
    vis.assign(n + 1 , false);

    for (int i = 1; i <= n; i++) cin >> gold[i];
    for (int i = 0; i < m; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            ans += DFS(i);
    }

    cout << ans << '\n';
    
    
}