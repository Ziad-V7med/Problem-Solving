#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

vector<vector<int>> adj , ans;
vector<bool> vis;
vector<int> tmp;

void DFS (int u) {
    vis[u] = true;
    tmp.push_back(u);
    
    for (auto v : adj[u]) 
        if (!vis[v])
            DFS(v);
    
    if (!tmp.empty())
        ans.push_back(tmp);
    tmp.clear();
}

signed main () {
    matador
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.assign(n + 1 , {});
        vis.assign(n + 1 , false);
        ans.clear();

        int root = -1;
        for (int i = 1; i <= n; i++) {
            int v; cin >> v;

            if (i == v)
                 root = i;

            else 
                adj[v].push_back(i);
            
        }

        DFS(root);
        
        cout << ans.size() << '\n';

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].size() << '\n';

            for (auto ch : ans[i])
                cout << ch << ' ';

            cout << '\n';
        }
        
        cout << "\n";
        
    }
    
}