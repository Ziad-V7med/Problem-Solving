#include <bits/stdc++.h>
#define int long long
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

signed main()
{
    matador 
    int n,m;    cin>>n>>m;
    string s,t; cin >>s>>t;

    map<string, int> freq;

    for (int i = 0; i <= n - m; i++) {
        string sub = s.substr(i, m);
        freq[sub]++;
    }
    cout << freq[t] << endl;
}