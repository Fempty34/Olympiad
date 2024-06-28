// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define all(a) a.begin(), a.end()
//#define int long long
//#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<'
//';}cout<<endl; #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >>
//(_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int N = 1e6 + 19;
const int b = 59;

mt19937_64 rnd(1);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);

    vector<ll> hashes(n + 1, 0);
    vector<ll> xores(n + 1, 0);
    for (int i = 1; i <= n; ++i) xores[i] = rnd();

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        hashes[u] ^= xores[v];
        hashes[v] ^= xores[u];
        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans = 0;
    map<ll, int> cnt_eq_hash;
    for (int i = 1; i <= n; i++) cnt_eq_hash[hashes[i]]++;
    for (auto p : cnt_eq_hash) {
        ll c = p.sc;
        ans += c * (c - 1) / 2;
    }

    for (int i = 1; i <= n; i++) {
        for (auto u : g[i]) {
            if (i < u && (hashes[i] ^ xores[u]) == (hashes[u] ^ xores[i]))
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
