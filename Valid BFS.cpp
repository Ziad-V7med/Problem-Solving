#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> order_bfs;

void BFS(int node) {
    queue<int> qu;
    
    qu.push(node);
    vis[node] = true;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        order_bfs.push_back(u);

        for (auto v : adj[u]) {
            if (!vis[v]) {
                qu.push(v);
                vis[v] = true;
            }
        }
    }
}

signed main() {
    matador
    cin >> n;

    adj.assign(n + 1, {});
    vis.assign(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> order(n) , idx(n + 1);
    
    for (int i = 0; i < n; i++) cin >> order[i] , idx[order[i]] = i;

    for (auto &v : adj) 
        sort(v.begin() , v.end() , [&] (int x , int y) {return idx[x] < idx[y];});

    BFS(1);
    
    cout << (order_bfs == order ? "YES" : "NO") << '\n';

}