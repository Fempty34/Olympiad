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

vector<int> g[N];
bool used[N];
int pows[N];
vector<pair<int, int>> ans;

void bfs(int s) {
    queue<int> q;

    used[s] = true;
    for(auto u: g[s]){
        used[u] = true;
        q.push(u);
        ans.pb({u, s});
    }
    
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!used[u]) {
                used[u] = true;
                ans.pb({u, v});
                q.push(u);
            }
        }
    }
} 


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;    

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        pows[u]++;
        pows[v]++;
    }

    int center = 1;
    for (int i = 1; i <= n; i++)
    {
        if(pows[i] > pows[center])
            center = i;
    }
    
    bfs(center);
    for(auto edge: ans) cout << edge.fr << " " << edge.sc << endl;



    return 0;
}
