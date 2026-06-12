#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n; 

vector<vector<int>> adj;

int max_dist, farthest_node;

void DFS (int u , int p , int dist) {
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = u;
    }

    for (auto v : adj[u])
        if (v != p) 
            DFS(v , u , dist + 1);
}

signed main() {
    matador
	cin >> n;
    adj.assign(n + 1 , {});

    for (int i = 0; i < n - 1; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    max_dist = -1;
    DFS(1 , -1 , 0);
    
    max_dist = -1;
    DFS(farthest_node , -1 , 0);

    cout << max_dist;

}
