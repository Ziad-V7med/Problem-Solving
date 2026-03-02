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
        int n,sum{},cnt{},penalty{}; cin>>n;  
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if(sum > 300 ) break;
            cnt++; penalty += sum;
        }
        cout<<cnt<<" "<<penalty<<"\n"; 
    }
}



