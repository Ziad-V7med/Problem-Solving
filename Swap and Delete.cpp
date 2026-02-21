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
      string s; cin>>s; int cnt0{},cnt1{},t{};
      for(auto it : s) it == '0' ? cnt0++ : cnt1++ ;
      for(int i = 0; i < s.size(); i++) {
         if (s[i] == '0' && cnt1>0) cnt1--,t++;
         else if (s[i] == '1' && cnt0>0) cnt0--,t++;
         else break;
      }
      cout<<s.size() - t <<"\n";
    }
}


