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
        int n; cin>>n; vector<int>v(n); map<int,int>freq;
        for (int i = 0; i < n; i++) {
            cin>>v[i]; freq[v[i]]++;
        }
        if(freq.size() == 1)       cout<<"YES\n";
        else if(freq.size() == 2) {
            int n1 = freq.begin() ->second;
            int n2 = freq.rbegin()->second;
            cout << (abs(n1 - n2) <= 1 ? "YES\n" : "NO\n");
        }
        else cout<<"NO\n";
        
    }
}



