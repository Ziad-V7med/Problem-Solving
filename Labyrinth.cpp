#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

vector<vector<char>> grid;
vector<vector<int>> level;
vector<vector<pair<int, int>>> parent;
vector<vector<char>> moves;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
string dir = "DURL";

int n , m; 

bool BFS (int r , int c) {
    queue<pair<int,int>> qu;

    qu.push({r , c});
    level[r][c] = 0;

    while (!qu.empty()) {

        int x = qu.front().first;
        int y = qu.front().second;

        qu.pop();

        for (int i = 0; i < 4; i++) {
            int nr = x + dx[i];
            int nc = y + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && level[nr][nc] == -1 && grid[nr][nc] != '#') {
                level[nr][nc] = level[x][y] + 1;
                parent[nr][nc] = {x , y};
                moves[nr][nc] = dir[i];
                
                if (grid[nr][nc] == 'B')
                    return true;

                qu.push({nr , nc});

            }
        }

    } 

    return false;
}

int main () {
    matador
    cin >> n >> m;
    grid.assign(n , vector<char>(m));
    level.assign(n , vector<int>(m , -1));
    parent.assign(n , vector<pair<int,int>>(m , {-1 , -1}));
    moves.assign(n , vector<char>(m));

    pair<int , int>A , B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'A') 
                A = {i , j};
                
            if (grid[i][j] == 'B') 
                B = {i , j};
        }
    }

    if (BFS(A.first , A.second)) {
        cout << "YES\n" << level[B.first][B.second] << '\n' ;

        string path = "";
        auto x = B;

        while (x != A) {
            path += moves[x.first][x.second];
            pair<int , int> p = parent[x.first][x.second];
            x = p;
        }

        reverse(path.begin() , path.end());

        cout << path;
        
    }
    else 
        cout << "NO\n";
   
}
