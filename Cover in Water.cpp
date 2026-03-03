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
        int n,cntDot{}; string s; bool dot3 = false; cin>>n>>s; 
        for (int i = 0; i < n; i++)
        { 
            if (i+2 < n && s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
                dot3 = true; break;
            }
            cntDot += (s[i] == '.');
        }
        cout<<(dot3 ? 2 : cntDot)<<"\n";
    }
}



