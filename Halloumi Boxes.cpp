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
        int n,k; cin>>n>>k; vector<int>v(n); bool sort = true;
        for (int i = 0; i < n; i++)  cin>>v[i];
        for (int i = 0; i < n-1; i++) if (v[i] > v[i+1]) sort = false;
        if (k == 1 && !sort) cout<<"NO\n";
        else cout<<"YES\n";    
    }
}



