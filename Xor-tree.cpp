#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n;

vector<vector<int>> adj;
vector<int> init , goal , ans;

struct node {
    int u , parent , level , odd_flips , even_flips;
};


void BFS () {
    queue<node> qu;

    qu.push({1 , 0 , 1 , 0 , 0});

    while (!qu.empty()) {
        int u = qu.front().u;
        int parent = qu.front().parent;
        int level = qu.front().level;
        int odd_flips = qu.front().odd_flips;
        int even_flips = qu.front().even_flips;

        qu.pop();

        int cur_flip = level % 2 ? odd_flips : even_flips;

        if (cur_flip & 1) 
            init[u] = 1 - init[u];
        
        if (init[u] != goal[u]) {
            ans.push_back(u);

            level % 2 ? odd_flips++ : even_flips++;
        }

        for (auto v : adj[u]) {
            if (v != parent)
                qu.push({v , u , level + 1 , odd_flips , even_flips});
        }
        
    }
}

signed main() {
    matador
    cin >> n;
    adj.assign(n + 1, {});
    init.assign(n + 1 , 0);
    goal.assign(n + 1 , 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) cin >> init[i];
    for (int i = 1; i <= n; i++) cin >> goal[i];
    
    BFS();

    cout << ans.size() << '\n';
    for (auto val : ans) 
        cout << val << '\n';
}