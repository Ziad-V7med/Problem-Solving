#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    pair<int , int> start , goal; cin >> start.first >> start.second >> goal.first >> goal.second;
    int n; cin >> n; set<pair<int , int>> segments;

    for (int i = 0; i < n; i++) {
        int r , a , b; cin >> r >> a >> b;

        for (int c = a; c <= b; c++) 
            segments.insert({r , c});
    }

    map<pair<int , int> , int> dist;

    int dx[] = {-1 ,-1 , -1 , 0 , 0 , 1 , 1 , 1};
    int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0, 1};
    
    queue<pair<int , int>> qu;

    qu.push(start);
    dist[start] = 0;

    while (!qu.empty()) {
        int r = qu.front().first;
        int c = qu.front().second;
        qu.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (segments.count({nr , nc}) && !dist.count({nr , nc})) {
                dist[{nr , nc}] = dist[{r , c}] + 1;

                if (nr == goal.first && nc == goal.second) {
                    cout << dist[{nr , nc}];
                    return 0;
                }
                    
                qu.push({nr , nc});
            }
        }
    }

    cout << "-1\n";
    
}