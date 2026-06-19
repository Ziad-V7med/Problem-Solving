#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> v(n) , depth(n + 1);

        for (int i = 0; i < n; i++) cin >> v[i];

        int node_idx = 0;
        int mx_depth = 0;

        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1])
                node_idx++;

            depth[v[i]] = depth[v[node_idx]] + 1;
            mx_depth = max (mx_depth , depth[v[i]]);
        }
       
        cout << mx_depth << '\n';
    }
    
}
