#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m;

vector<vector<int>> adj , team;
vector<bool> vis;
vector<int> v1 , v2 , tmp;


void DFS (int u) {
    vis[u] = true;
    tmp.push_back(u);

    for (auto v : adj[u])
        if (!vis[v])
            DFS(v);
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

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS(i);

            if (tmp.size() > 3) {
               cout << "-1\n"; 
               return 0;
            }

            if (tmp.size() == 3)
                team.push_back(tmp);
                
            if (tmp.size() == 2) {
                v2.push_back(tmp[0]);
                v2.push_back(tmp[1]);
            }

            if (tmp.size() == 1) {
                v1.push_back(tmp[0]);
            }
                
            tmp.clear();
        }
    }

    if (v1.size() < v2.size() / 2 || (v1.size() - v2.size() / 2) % 3 != 0) {
            cout << "-1\n";
            return 0; 
    }

    for (auto t : team) 
        cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';

    int idx1 = 0;

    for (int i = 0; i < v2.size(); i += 2)
        cout << v2[i] << ' ' << v2[i + 1] << ' ' << v1[idx1++] << '\n';
        
    for (int i = idx1; i < v1.size(); i += 3)
        cout << v1[i] << ' ' << v1[i + 1] << ' ' << v1[i + 2] << '\n';
            
}