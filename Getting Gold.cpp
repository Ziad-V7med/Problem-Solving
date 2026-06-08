#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

int n , m , total; 

vector<vector<char>> grid;
vector<vector<bool>> vis;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

void DFS (int x , int y) {
   vis[x][y] = true;
   
   if (grid[x][y] == 'G')
      total++;

   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'T') 
            return;
   }
   
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != '#')
         DFS(nx , ny);
      
   }
   
}

int main () {
   matador
   while (cin >> m >> n) {
      grid.assign(n , vector<char>(m));
      vis.assign(n , vector<bool>(m));
      total = 0;

      pair<int , int> pos;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
         {
            cin >> grid[i][j];
            if (grid[i][j] == 'P')
               pos = {i , j};
         }
      }

      DFS(pos.first , pos.second);
      
      cout << total << '\n';
   }
   
  

 
}