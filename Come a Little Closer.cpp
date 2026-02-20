#include <bits/stdc++.h>
#define int long long
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

void solve(){
  int n; cin>>n; vector<pair<int,int>>x(n),y(n);
  for (int i = 0; i < n; i++)
  {
     cin>>x[i].first; x[i].second = i;
     cin>>y[i].first; y[i].second = i;
  }
  if (n == 1) {
      cout << "1\n"; return;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int ans = INT64_MAX;
  for (auto index : {x[0].second , x[n-1].second , y[0].second , y[n-1].second})
  {
     int lx = x[0].second == index ? x[1].first : x[0].first;
     int hx = x[n-1].second == index ? x[n-2].first : x[n-1].first;
     int ly = y[0].second == index ? y[1].first : y[0].first;
     int hy = y[n-1].second == index ? y[n-2].first : y[n-1].first;
     int area = (hx - lx + 1) * (hy - ly + 1);
     ans = min (ans , area);
     if (ans == n-1) ans += min(hx - lx + 1, hy - ly + 1);
  }
  cout<< ans << "\n";
}

signed main()
{
    matador
    int t; cin>>t;
    while (t--) solve();
}
