#include <bits/stdc++.h>
#define int long long
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

signed main()
{
    matador 
    int t; cin>>t;
    while (t--)
    {
        int n,m; cin>>n>>m; bool check = false; 
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
        for (int i = 0; i < n; i++)
        {
            for (int z = 0; z < m; z++)
            {
                if (v[i][z] == 'p'){
                    if(z+2 < m && v[i][z+1] == 'i' && v[i][z+2] == 'e') {
                        check = true; break;
                    }
                    if(z-2 >= 0 && v[i][z-1] == 'i' && v[i][z-2] == 'e') {
                        check = true; break;
                    }
                    if(i-2 >= 0 && v[i-1][z] == 'i' && v[i-2][z] == 'e') {
                        check = true; break;
                    }
                    if(i+2 < n && v[i+1][z] == 'i' && v[i+2][z] == 'e') {
                        check = true; break;
                    }
                    if(i-2 >= 0 && z+2 < m && v[i-1][z+1] == 'i' && v[i-2][z+2] == 'e') {
                        check = true; break;
                    }
                    if(i+2 < n && z-2 >= 0 && v[i+1][z-1] == 'i' && v[i+2][z-2] == 'e') {
                        check = true; break;
                    }
                    if(i-2 >= 0 && z-2 >= 0 && v[i-1][z-1] == 'i' && v[i-2][z-2] == 'e') {
                        check = true; break;
                    }
                    if(i+2 < n && z+2 < m && v[i+1][z+1] == 'i' && v[i+2][z+2] == 'e') {
                        check = true; break;
                    }
                }
            }
            if (check) break;   
        }
        cout << (check ? "Cutie Pie!\n" : "Sorry Man\n");
    }
}



