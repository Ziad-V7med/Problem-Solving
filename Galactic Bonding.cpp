#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long
using namespace std;

int n , id = 0;
double d;

vector<pair<double , double>> stars;
vector<bool> vis;

double Distance (pair<double , double> star1 , pair<double , double> star2) {
    return sqrt((star1.first - star2.first) * (star1.first - star2.first) + (star1.second - star2.second) * (star1.second - star2.second));
}

void DFS (int u) {
    vis[u] = true;

    for (int i = 0; i < n; i++)
        if (!vis[i] && Distance(stars[u] , stars[i]) <= d)
            DFS(i);
}

signed main() {
    matador
	int t; cin >> t;
    while (t--) {
        cin >> n >> d;
        stars.assign(n , {});
        vis.assign(n , false);

        for (int i = 0; i < n; i++) cin >> stars[i].first >> stars[i].second;

        int groups = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS(i);
                groups++;
            }
        }

        cout << "Case " << ++id << ": " << groups << '\n';
                
    }
    
}
