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
        int n,x; cin>>n>>x; vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int mx_dif = v[0];
        for (int i = 0; i < n-1; i++) mx_dif = max(mx_dif,v[i+1] - v[i]);
        cout << max(mx_dif , 2 * (x - v[n-1])) <<"\n";
    }
}



