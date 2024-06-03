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
// #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

vector<int> g[N];
vector<int> tree[N];
vector<int> order;
vector<pair<int, int>> dp(N);

int costs[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    order.pb(s);
    
    vector<int> d(N, -1);
    d[s] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                tree[v].pb(u);
                order.pb(u);
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
} 

vector<int> ans;
int used[N];
void dfs(int v, int state){
    used[v] = 1;
    bool flag = false;
    if (dp[v].fr > dp[v].sc){
        ans.pb(v);
        flag = true;
    }
    else if(dp[v].fr <= dp[v].sc && !state){
        ans.pb(v);
        flag = true;
    }
    for(auto u : tree[v]){
        if(!used[u]){
            dfs(u, flag);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
    }
    bfs(1);
    reverse(all(order));

    if( n == 1) {
        cout << costs[1] << " " << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    
    for(int i = 1; i <= n; i++)
        dp.pb({0, costs[i]});
    

    for(auto v : order){
        int s1 = 0;
        for(auto u: tree[v]){
            s1 += dp[u].sc;
        }

        int s2 = 0;
        for(auto u: tree[v]){
            s2 += min(dp[u].sc, dp[u].fr);
        }
        dp[v].fr = s1;
        dp[v].sc = s2 + costs[v];
    }
    
    dfs(1, 1);
    cout << min(dp[1].fr, dp[1].sc) << " " << ans.size() << endl;


    for(auto x : ans)
        cout << x << " ";

    return 0;
}
