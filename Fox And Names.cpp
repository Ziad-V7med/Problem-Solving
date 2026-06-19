#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

signed main () {
    matador
    int n; cin >> n; vector<string> names(n);
    
    for (int i = 0; i < n; i++) cin >> names[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26);

    for (int i = 0; i < n - 1; i++) {
        string s1 = names[i];
        string s2 = names[i + 1];

        if (s1.size() > s2.size() && s2 == s1.substr(0 , s2.size())) {
            cout << "Impossible";
            return 0;
        }

        for (int i = 0; i < min(s1.size() , s2.size()); i++) {
            if (s1[i] != s2[i]) {
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                indegree[s2[i] - 'a']++;

                break;
            }
        }
    }

    string ans = "";
    queue<int> qu;

    for (int i = 0; i < 26; i++) 
        if (!indegree[i])
            qu.push(i);
    
    while (!qu.empty()) {
        int u = qu.front();
        ans.push_back(u + 'a');
        qu.pop();

        for (auto v : adj[u]) {
            indegree[v]--;
            
            if (!indegree[v])
                qu.push(v);
        } 
    }
    
    cout << (ans.size() == 26 ? ans : "Impossible") << '\n';

}