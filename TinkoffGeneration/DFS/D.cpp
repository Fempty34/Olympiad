// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define all(a) a.begin(), a.end()
#define int long long
// #define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
// #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e18 + 1;
const int MOD = 1e9;
const int N = 1e5 + 19;

vector<pair<int, int>> g[N];
vector<int> order;

int used[N];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u.fr]) {
            dfs(u.fr);
        }
    }
    order.pb(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i])
            dfs(i);
    }
    reverse(all(order));

    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = order[i];
        for (auto u : g[v]) {
            dist[u.fr] = min(dist[u.fr], dist[v] + u.sc);
        }
    }
    if (dist[t] >= 1e18 + 1 - 1e17) {
        cout << "Unreachable";
    } else {
        cout << dist[t];
    }

    return 0;
}
