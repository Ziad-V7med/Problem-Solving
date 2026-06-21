#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , m;

vector<vector<char>> grid(100 , vector<char>(100));
int dist[100][100][2];

struct node {
    int x , y;
    bool door;
};

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int BFS (int x , int y) {
    queue<node> qu;

    qu.push({x , y , 0});
    dist[x][y][0] = 0;

    while (!qu.empty()) {
        int r = qu.front().x;
        int c = qu.front().y;
        bool d = qu.front().door;
        qu.pop();

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
            return dist[r][c][d] + 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != 'W') {

                if (grid[nr][nc] == 'D' && !d) continue;
                
                bool state_door = d;

                if (grid[nr][nc] == 'O') state_door = true;
                else if (grid[nr][nc] == 'C') state_door = false;
                
                if (dist[nr][nc][state_door] == -1) {
                    qu.push({nr , nc , state_door});
                    dist[nr][nc][state_door] = dist[r][c][d] + 1;
                }
            }
        }
    }

    return -1;
}

signed main () {
    matador
    while (cin >> n >> m) {
        if (n == -1 && m == -1) 
            break;

        memset(dist, -1, sizeof(dist));

        pair<int , int> start;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];

                if (grid[i][j] == 'H')
                    start = {i , j};
            }
        }

        cout << BFS(start.first , start.second) << '\n';

    }
    
    
}