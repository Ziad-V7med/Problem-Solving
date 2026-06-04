#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

vector<string> grid;
vector<vector<bool>> vis;

int n , m; 

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

void DFS (int r , int c) {
    vis[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[r][c] == grid[nr][nc]) 
            DFS(nr , nc);
    }
    
}


int main () {
    matador
    cin >> n >> m;
    vis.assign(n , vector<bool>(m , false));

    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        grid.push_back(row);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                DFS(i , j);
                ans++;
            }
        }
    }
    
    cout << ans << '\n';
    
}
