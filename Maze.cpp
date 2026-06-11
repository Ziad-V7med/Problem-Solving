#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;


int n , m , k;  

vector<vector<char>> maze;
vector<vector<bool>> vis;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int visited = 0 , dot = 0;

void DFS (int x , int y) {
     vis[x][y] = true;
     
     if (visited != dot - k)
        visited++;
     else 
        maze[x][y] = 'X';

     for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && !vis[nx][ny])
            DFS(nx , ny);
     }
     
}

signed main() {
    matador
	cin >> n >> m >> k;
    maze.assign(n , vector<char>(m));
    vis.assign(n , vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           cin >> maze[i][j];
           dot += (maze[i][j] == '.');
        }
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (!vis[i][j] && maze[i][j] != '#') 
                DFS(i , j);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << maze[i][j];
        cout << '\n';
    }
    
}
