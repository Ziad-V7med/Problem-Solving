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
        int n,cnt{}; cin>>n;
        vector<vector<bool>>rectangle(101,vector<bool>(101));
        for (int z = 0; z < n; z++)
        {
            int x,y,k; cin>>x>>y>>k;
            for (int i = 0; i < k; i++)
            {
                for (int j = x; j < y; j++)
                {
                    if(!rectangle[i][j]) cnt++;
                    rectangle[i][j] = true;
                }
            }
        }
        cout << cnt << "\n";
    }
    
}