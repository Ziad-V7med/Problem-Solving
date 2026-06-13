#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

vector<vector<pair<int , int>>> adj;
vector<int> ans;

void DFS (int u , int p , int last) {

    for (auto v : adj[u]) 
        if (v.first != p) 
            ans[v.second] = 5 - last,DFS(v.first , u , 5 - last);
    
}

void solve () {
    int n; cin >> n;

    adj.assign(n + 1 , {});
    ans.assign(n , 0);

    for (int i = 0; i < n - 1; i++) {
        int u , v; cin >> u >> v;

        adj[u].push_back({v , i});
        adj[v].push_back({u , i});
    }

    int root = -1;

    for (int i = 1; i <= n; i++) 
        if (adj[i].size() > 2) {
            cout << "-1\n";
            return;
        }
            
        else if (adj[i].size() == 1)
            root = i;

    DFS(root , -1 , 2);
    
    for (int i = 0; i < n - 1; i++) 
        cout << ans [i] << ' ';

    cout << '\n';
}

signed main () {
    matador
    int t; cin >> t;
    while (t--)  
        solve();
    
    
}