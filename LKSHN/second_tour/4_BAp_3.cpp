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
int b[N];
int a[N];
vector<int> dp(N, INF);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    deque<int> q;
    q.push_front(1);
    
    if(a[1] == b[0])
        dp[1] = 1;
    else
        dp[1] = 0;

    vector<int> d(N, -1);
    d[1] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (int u : g[v]) {
            if (d[u] == -1) {
                if(a[u] == b[dp[v]]){
                    dp[u] = min(dp[u], dp[v] + 1);
                    q.push_back(u);
                }
                else{
                    dp[u] = min(dp[u], dp[v]);
                    q.push_front(u);
                }
                d[u] = d[v] + 1;
            }
        }
    }

    if(dp[n] >= k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}
