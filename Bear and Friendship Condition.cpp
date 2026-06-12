#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m;

vector<vector<int>> adj;
vector<bool> vis;

int node , edge;

void DFS (int u) {
    vis[u] = true;
    node++;

    for (auto v : adj[u])
        if (!vis[v]) 
            DFS(v);
        
    edge += adj[u].size();      
}

signed main () {
    matador    
    cin >> n >> m;
    adj.assign(n + 1 , {});
    vis.assign(n + 1 , false);
    
    for (int i = 0; i < m; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool network = true;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            node = edge = 0;
            DFS(i);

            if (edge / 2 != node * (node - 1) / 2) {
                network = false;
                break;
            }
                
        }
    }

    cout << (network ? "YES" : "NO") << '\n';
              
}
