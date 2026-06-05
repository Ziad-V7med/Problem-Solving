#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

map<int , vector<int>> adj;
map<int , bool> vis;

void DFS (int u) {
    vis[u] = true;
    
    for (auto v : adj[u]) 
        if (!vis[v])
            DFS(v);
    
}

signed main () {
    matador    
    int u , v , k = 1; 

    map<int , int> indegree;
    set<int> all_nodes;
    
    while (true) {
        cin >> u >> v;
        
        if (u == -1 && v == -1)
        break;
        
        if (u == 0 && v == 0) {

            if (all_nodes.empty()) {
                cout << "Case " + to_string(k) + " is a tree." << '\n';
                k++;
                continue;
            }

            int root = 0 , start = -1;
            bool istree = true;

            for (auto node : all_nodes) {
                if (indegree[node] == 0) {
                    root++;
                    start = node;
                }
                else if (indegree[node] > 1) {
                    istree = false;
                    break;
                }
            }

            if (root != 1 || !istree) {
                cout << "Case " + to_string(k) + " is not a tree." << '\n';
                k++;
                adj.clear();
                vis.clear();
                indegree.clear();
                all_nodes.clear();

                continue;
            }

            DFS(start);

            bool allvisit = true;
            for (auto node : all_nodes) {
                if (vis[node] != true) {
                    allvisit = false;
                    break;
                }      
            }

            cout << (allvisit ? "Case " + to_string(k) + " is a tree." : "Case " + to_string(k) + " is not a tree.") << '\n';
            k++;

            adj.clear();
            vis.clear();
            indegree.clear();
            all_nodes.clear();

            continue;
        }
            
        adj[u].push_back(v);
        indegree[v]++;
        all_nodes.insert(u);
        all_nodes.insert(v);
  
    }
    
}