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
      int n,f,a,b; cin>>n>>f>>a>>b; vector<int>v(n+1); 
      for (int i = 1; i <= n; i++) cin>>v[i]; 
      bool can = true;
      for (int i = 1; i <= n; i++)
      {
        f -= min((v[i]-v[i-1])*a , b);
        if (f <= 0) {
           can = false; break;
        }
      }
      if(can) cout<<"YES\n"; 
      else cout<<"No\n";
    }
}




