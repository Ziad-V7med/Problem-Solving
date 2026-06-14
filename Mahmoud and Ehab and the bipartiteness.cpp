#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n;

vector<vector<int>> adj;
vector<int> color;

int cnt_1 = 0, cnt_2 = 0;

void BFS (int node) {
    queue<int> qu;

    qu.push(node);
    color[node] = 1;
    cnt_1++;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) {
            if (!color[v]) {
                qu.push(v);
                color[v] = 3 - color[u];

                cnt_1 += (color[v] == 1);
                cnt_2 += (color[v] == 2);
            }
        }   
    }
    
}

signed main() {
    matador
    cin >> n;
    adj.assign(n + 1, {});
    color.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(1);

    cout << cnt_1 * cnt_2 - (n - 1);
       
}