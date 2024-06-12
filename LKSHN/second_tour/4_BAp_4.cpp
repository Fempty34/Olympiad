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
const int N = 1e6 + 19;

vector<int> g[N];
vector<int> tree[N];
vector<int> order;
vector<int> d(N, -1);
vector<int> p(N);
int n, k;

void hanging(int s) {
    queue<int> q;
    q.push(s);
    order.pb(s);
    
    //vector<int> d(N, -1);
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
                p[u] = v;
            }
        }
    }
} 

bool ans[N];


void update(int s, int l){
    if(!ans[s]) d[s] -= l;
    for(auto u : tree[s]){
        if(!ans[u])
            update(u, l);
        else
            update(u, d[u]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    hanging(n);
    //reverse(all(order));

    int cnt = n - k - 1;
    //for(int j = 1; j <= n; j++){
    //    cout << j << ": " << d[j] << ", ";
    //}
    
    ans[n] = true;

    for(int i = n - 1; i > 0; i--){
        if(cnt == 0){break;}
        if(d[i] <= cnt && !ans[i]){
            int v = i, last = i;
            //cout << endl;
            while(!ans[v]){
                //cout << v << " "; 
                ans[v] = true;
                last = v;
                v = p[v];
            }
            //cout << v << endl;
            update(last, d[i]);
            //for(int j = 1; j <= n; j++){
            //    cout << j << ": " << d[j] << ", ";
            //}
            //cout << endl;
            cnt -= d[i];
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!ans[i])
            cout << i << " ";
    }



    return 0;
}
