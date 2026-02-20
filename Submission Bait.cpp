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
      int n; cin>>n; vector<int>v(n); map<int,int>mp;
      for (int i = 0; i < n; i++) {
         cin>>v[i]; mp[v[i]]++;
      }
      bool win = false;
      for(auto it = mp.begin(); it != mp.end() ; it++ ){
         if (it->second & 1) {
            win = true; break;
         }
      }
      if (win) cout<<"YES\n";
      else cout<<"NO\n";
    }
}




