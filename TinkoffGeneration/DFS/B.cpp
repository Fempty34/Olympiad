// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <cmath>
#include <sAASdf>

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

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 1e5 + 19;

vector<int> g[N];
vector<int> order;

int used[N];
int cycle[N];

bool flag = true;

void dfs(int v) {
    used[v] = 1;
    cycle[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            if (cycle[u] == 1) {
                flag = true;
                break;
            }
            dfs(u);
        }
    }
    cycle[v] = 0;
    order.pb(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        edges[i] = {u, v};
    }

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        order.pb(x);
    }

    int perenum[N];
    for (int i = 0; i < n; i++) {
        perenum[order[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        if (perenum[edges[i].fr] >= perenum[edges[i].sc])
            flag = false;
    }


    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
