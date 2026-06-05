#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    int n , m; cin >> n >> m;
    vector<bool> found(n + 1);
        
    while (m--) {
        int u , v; cin >> u >> v;

        found[u] = found[v] = true;
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!found[i]) {
            root = i;
            break;
        }
    }

    cout << n - 1 << '\n';
    
    for (int i = 1; i <= n; i++) 
        if (root != i) 
            cout << root << ' ' << i << '\n';
    
}