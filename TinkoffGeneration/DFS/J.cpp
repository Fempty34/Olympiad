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
const int N = 1e5 + 19;

vector<int> g[N];
vector<int> tree[N];
vector<int> order;
int h[N];


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
void dfs(int v){
    used[v] = 1;
    for(auto u : g[v]){
        if(!used[u]){
            dfs(u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(1);
    reverse(all(order));


    for(int i = 0; i < n; i++) {
        for(auto u : tree[order[i]]){
            h[order[i]] = max(h[order[i]], h[u] + 1);
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> sons;
        for(auto u : tree[order[i]]){
            sons.pb(h[u]);
        }
        if(sons.size() >= 3){
            sort(all(sons));
            reverse(all(sons));
            
        }

    }
    
    
    

    return 0;
}
