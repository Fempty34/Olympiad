// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define all(a) a.begin(), a.end()
//#define int long long
#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
// #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5000 + 1;

vector<pair<int, ll>> g[N];
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
    int n, m;
    ll T;
    cin >> n >> m >> T;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    for (int i = 1; i <= m; i++) {
        if (!used[i])
            dfs(i);
    }
    
    //int perenum[N];
    //for (int i = 0; i < order.size(); i++)
    //{
    //    perenum[order[i]] = i;
    //}
    //print_array(order);
    
    vector<ll> sub1(n + 1, INF);
    vector<vector<ll>> dp(n + 1, sub1);
    vector<int> sub2(n + 1);
    vector<vector<int>> p(n + 1, sub2);
    dp[n][1] = 0;

    for (int i = 0; i < n; i++) 
    {
        int v = order[i];
        for(int i = 2; i <= n; i++){
            for(auto u: g[v]){
                if(dp[u.fr][i - 1] + u.sc <= T && dp[v][i] > dp[u.fr][i - 1] + u.sc){
                    dp[v][i] = dp[u.fr][i - 1] + u.sc;
                    p[v][i] = u.fr;
                }
            }
        }
    }   
    ll x, k;

    for(int i = n; i >= 1; i--){
        if(dp[1][i] != INF){
            //cout << i << endl;
            x = p[1][i];
            k = i;
            break;
        }
    }
    //cout << x << " " << k << endl;
    cout << k << endl;
    cout << 1 << " ";
    
    while(x != n){
        cout << x << " ";
        x = p[x][--k];
    }
    cout << n << endl;

    return 0;
}
