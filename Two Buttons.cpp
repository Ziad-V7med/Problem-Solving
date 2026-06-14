#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m;
map<int , int> dist;

void BFS (int node) {
    queue<int> qu;

    qu.push(node);
    dist[node] = 0;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        if (u == m) return;

        if (u - 1 >= 1 && dist.find(u - 1) == dist.end()) {
            qu.push(u - 1);
            dist[u - 1] = dist[u] + 1;
        }
           
        if (u * 2 <= 1e4 && dist.find(u * 2) == dist.end()) {
            qu.push(u * 2);
            dist[u * 2] = dist[u] + 1;
        } 
    }
    
}

signed main () {
    matador
    cin >> n >> m;

    BFS(n);

    cout << dist[m];
    
}