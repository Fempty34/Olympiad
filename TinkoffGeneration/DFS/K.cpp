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
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

int c[N];
map<int, string> orientation;

vector<int> used(N);
void dfs(int v, vector<pair<int, int>> g[N]){
    used[v] = 1;
    for(auto u : g[v])
        if(!used[u.fr]){
            orientation[u.sc] = "->";
            dfs(u.fr, g);
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<pair<int,int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        edges.pb({u, v});
    }
    
    for (int i = 1; i <= n; i++) cin >> c[i];

    map<int, vector<vector<int>>> to_proc;
    vector<string> ans(m);

    for(int i = 0; i < m; i++){
        int u = edges[i].fr;
        int v = edges[i].sc;
        if(c[u] == c[v])
            to_proc[c[u]].pb({u, v, i});
        else if(c[u] > c[v])
            ans[i] = "->";
        else
            ans[i] = "<-";
        
    }

    for(auto [c, graph] : to_proc){

        vector<pair<int,int>> g[N];

        for(auto x : graph){
            g[x[0]].pb({x[1], x[2]});
            g[x[1]].pb({x[0], x[2]});
            orientation[x[2]] = "";
        }

        dfs(graph[0][0], g);

        for(auto [e, o] : orientation){
            if(o == "")
                ans[e] = "<-";
            else
                ans[e] = o;
        }

        used.clear();
        orientation.clear();
    }

    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }
    


    return 0;
}
