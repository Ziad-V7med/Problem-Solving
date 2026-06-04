#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

int n , m;

vector<vector<int>> adj;
vector<int> level , parent;

void BFS (int node) {
    queue<int> qu;

    qu.push(node);
    level[node] = 0;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        
        for (auto v : adj[u]) {
            if (level[v] == -1) {
                qu.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
}

void Path (int node) {
    if (node == -1)
         return;

    Path(parent[node]); 
    cout << node << ' ';
}


int main () {
    matador
    cin >> n >> m;
   
    adj.assign(n + 1 , {});
    level.assign(n + 1 , -1);
    parent.assign(n + 1 , -1);

    for (int i = 0; i < m; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    BFS(1);

    if (level[n] == -1) 
        cout << "IMPOSSIBLE";

    else {
        cout << level[n] + 1 << '\n';
        Path(n);
    }
}
