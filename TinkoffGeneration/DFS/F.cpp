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

vector < int > g[N];
vector < int > order;

int used[N];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
    order.pb(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> costs(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> costs[i];
    }

    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            g[i].pb(x);
        }
    }

    dfs(1);

    int cnt = 0;
    for (auto el : order)
        cnt += costs[el];

    cout << cnt << ' ' << order.size() << endl;
    for (auto el : order)
        cout << el << ' ';
    

    return 0;
}