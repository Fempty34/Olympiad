//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

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
#define fr first 
#define sc second 
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 2*1e5 + 19;

bool flag = false;
vector<int> g[N];
vector<int> order;
vector<int> used;
int costs[N];
int cycle[N];

void dfs(int v, int x){
    used[v] = 1;
    cycle[v] = 1;
    for(auto u : g[v]){
        if(cycle[u]){flag = true; break;}
        if(costs[u] <= x && !used[u])
            dfs(u, x);
    }
    cycle[v] = 0;
    order.pb(v);
}


bool check(int n, int x, int k){
    for(int i = 1; i <= n; i++){
        if(!used[i] && costs[i] <= x)
            dfs(i, x);
    }

    //reverse(all(order));
    if(flag){
        used.assign(n + 1, 0);
        order.clear();
        flag = false;
        return true;
    }
    int m = 0;
    vector<int> dp(n + 1, 1);
    for(int i = 0; i < order.size(); i++){
        int v = order[i];
        for(auto u : g[v]){
            if(costs[u] <= x){
                dp[v] = max(dp[v], dp[u] + 1);
            }
        }
        m = max(m, dp[v]);
    }
    //cout << " -> " << m << endl;
    used.assign(n + 1, 0);
    order.clear();
    flag = false;
    if(m >= k)
        return true;
    else
        return false;
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    used.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> costs[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> v >> u;
        g[v].pb(u);
    }
    
    int l = -1;
    int r = INF;

    while(l < r){
        int m = (l + r) / 2;
        //cout << m << " " << check(n, m, k) << endl;
        if(check(n, m, k))
            r = m;
        else
            l = m + 1;
    }
    //cout << check(n, r, k) << endl;

    if(l == INF)
        cout << -1 << endl;
    else if(check(n, l, k))
        cout << l << endl;
    else
        cout << r << endl;
    return 0;
}