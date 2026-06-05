#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    int n , m; cin >> n >> m;
    vector<int> indegree (n + 1);
        
    while (m--) {
        int u , v; cin >> u >> v;

        indegree[u]++;
        indegree[v]++;
    }

    int deg_1 = 0,deg_2 = 0 , center = 0;
    for (int i = 1; i <= n; i++) 
        if (indegree[i] == 1)
            deg_1++;
        else if (indegree[i] == 2)
            deg_2++;
        else if (indegree[i] == n - 1)
            center++;
        

    if (deg_1 == 2 && deg_2 == n - 2) 
        cout << "bus topology"; 

    else if (deg_2 == n) 
        cout << "ring topology";
        
    else if (center == 1 && deg_1 == n -1)
        cout << "star topology";

    else 
        cout << "unknown topology";
    
}