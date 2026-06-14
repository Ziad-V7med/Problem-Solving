#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

string s , e;

vector<vector<int>> dist;

int dx[] = { 1 , -1 , 1 , -1 , 2 , -2 , 2 , -2 };
int dy[] = { 2 , 2 , -2 , -2 , 1 , 1 , -1 , -1 };

void BFS (int x , int y) {
    queue<pair<int , int>> qu;

    qu.push({x , y});
    dist[x][y] = 0;

    while (!qu.empty()) {
        int r = qu.front().first;
        int c = qu.front().second;
        qu.pop();

        if (r == e[0] - 'a' + 1 && c == e[1] - '0')
            return;

        for (int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8 && dist[nr][nc] == -1) {
                qu.push({nr , nc});
                dist[nr][nc] = dist[r][c] + 1;
            }
        }
    }
    
}

signed main () {
    matador
    while (cin >> s >> e) {

        dist.assign(9 , vector<int>(9 , -1));

        BFS(s[0] - 'a' + 1 , s[1] - '0');

        cout << "To get from " << s << " to " << e << " takes " << dist[e[0] - 'a' + 1][e[1] - '0'] << " knight moves.\n";
    }
    
}