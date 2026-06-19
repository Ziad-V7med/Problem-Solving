#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n, k; 

vector<vector<int>> adj;
vector<int> friends , dist;

void BFS () {
    queue<int>qu;

    for (auto fr : friends) {
        qu.push(fr);
        dist[fr] = 0; 
    }

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) {
             if (dist[v] == -1) {
                qu.push(v);
                dist[v] = dist[u] + 1;
             }
        }
    }
}

bool DFS (int u , int p , int depth) {
    if (depth >= dist[u]) 
        return false;

    if (u != 1 && adj[u].size() == 1)
        return true;

    for (auto v : adj[u]) 
        if (v != p)
            if (DFS(v , u , depth + 1))
                return true;

    return false;
}

signed main() {
    matador
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
    
        adj.assign(n + 1, {});
        dist.assign(n + 1, -1);
        friends.assign(k , 0);
    
        for (int i = 0; i < k; i++) cin >> friends[i];
    
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
    
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BFS();

        cout << (DFS(1 , 0 , 0) ? "YES" : "NO") << '\n';    

    }
    
}