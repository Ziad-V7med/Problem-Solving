#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m; 

vector<vector<int>> adj;
vector<int> cat;

int restaurant = 0;

void DFS (int u , int p , int consecutive_cats) {
    consecutive_cats = cat[u] ? consecutive_cats + 1 : 0;
    
    if (consecutive_cats > m) return;

    for (auto v : adj[u]) {
        if (v != p) {
            DFS(v , u , consecutive_cats);
        }
    }

    if (p != -1 && adj[u].size() == 1) restaurant++;
    
}

signed main() {
    matador
	cin >> n >> m;
    adj.assign(n + 1 , {});
    cat.assign(n + 1 ,0);

    for (int i = 1; i <= n; i++) cin >> cat[i];

    for (int i = 0; i < n - 1; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DFS(1 , -1 , 0);

    cout << restaurant;
    
   
}
