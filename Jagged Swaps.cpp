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
        int n; cin>>n; vector<int>v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        cout<<(v[0] == 1 ? "YES\n" : "NO\n");
    }
}



