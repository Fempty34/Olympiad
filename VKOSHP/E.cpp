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
#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define qfor(_n) for(int i=0;i<_n;i++)
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 3*1e5 + 19;

mt19937 rnd(197);
int used[N];
set<int> ans;
vector<int> h;
vector<int> g[N];

void dfs(int v) {
    used[v] = true;
    bool flag = false;
    for (auto u : g[v]) {
        flag = true;
        if (!used[u]) {
            dfs(u);
        }
    }
    if (!flag) ans.insert(v);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    h.resize(n);
    scan_array(h);
    int m; cin >> m;
    qfor(m) {
        int a, b; cin >> a >> b;
        if(h[a - 1] < h[b - 1])
            g[b].pb(a);
        else if (h[a - 1] > h[b - 1])
            g[a].pb(b);
    }
    dfs(1);
    for(auto x : ans) {
        cout << x << " ";
    }

    return 0;
}
