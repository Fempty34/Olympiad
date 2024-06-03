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
const int N = 2*1e5 + 1;

vector<vector<int>> g;
vector<int> vertex_proc;
int used[N];
int cnt = 0;


vector<int> make_path(int s) {
    queue<int> q;
    q.push(s);
    
    vector<int> d(N, -1), p(N, -1);
    d[s] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    return p;
} 

int max_path(int s) {
    queue<int> q;
    q.push(s);
    
    vector<int> d(N, -1), p(N, -1);
    d[s] = 0;
    int m = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
                m = max(m, d[u]);
                p[u] = v;
            }
        }
    }

    return m;
} 


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        g.resize(n + 1);
        int a, b;
        cin >> a >> b;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        vector<int> p = make_path(a);
        vector<int> path;
        int v = b;
        path.pb(v);
        while(v != a){
            v = p[v];
            path.pb(v);
        }

        int s = path.size() - 1;
        int h = 0;
        for(int i =1; i<=n; i++){
            if(g[i].size() == 1 &&)
                h++;
        }

        int ans = 2*(n - 1) + g[path[s / 2]].size() - h;
        cnt = 0;
        
        //dfs(path[s / 2]);
        ans += cnt - 1;
        
        int dist = max_path(path[s / 2]);
        //cout << dist + 1 << endl;
        //cout << ans << " " << dist << endl;
        cout << ans - dist << endl;

        g.clear();
        for(int i = 1; i <= n; i++){
            used[i] = 0;
        }
        cnt = 0;
        vertex_proc.clear();
    }
    return 0;
}