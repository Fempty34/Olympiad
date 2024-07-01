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
#define qfor(_n) for(int i=0;i<(_n);i++)
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 1e5 + 19;

mt19937 rnd(197);

vector<int> g1[N];
vector<int> g2[N];

vector<int> tree1[N];
vector<int> tree2[N];


vector<int> hanging1(int s) {
    queue<int> q;
    vector<int> order;
    vector<int> d(N, -1);

    q.push(s);
    order.pb(s);
    d[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u : g1[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
                order.pb(u);
                tree1[v].pb(u);
            }
        }
    }
    reverse(all(order));
    return order;
}

vector<int> hanging2(int s) {
    queue<int> q;
    vector<int> order;
    vector<int> d(N, -1);

    q.push(s);
    order.pb(s);
    d[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u : g2[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
                order.pb(u);
                tree2[v].pb(u);
            }
        }
    }
    reverse(all(order));
    return order;
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int r1, r2;
    cin >> r1 >> r2;

    qfor(n - 1) {
        int a, b;
        cin >> a >> b;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    
    qfor(n - 1) {
        int a, b;
        cin >> a >> b;
        g2[a].pb(b);
        g2[b].pb(a);
    }

    vector<int> order1 = hanging1(r1);
    vector<int> order2 = hanging2(r2);

    //print_array(order1);
    //print_array(order2);

    vector<int> dp1(n + 1, 0);
    vector<int> dp2(n + 1, 0);

    map<vector<int>, int> hashes;

    int cnt = 1;

    for(auto v : order1) {
        vector<int> sons;
        for(auto u : tree1[v]) 
            sons.pb(dp1[u]);
        sort(all(sons));
        if(hashes.find(sons) == hashes.end()) {
            hashes[sons] = cnt;
            cnt++;
            dp1[v] = hashes[sons];
        }
        else {
            dp1[v] = hashes[sons];
        }
    }
    
    for(auto v : order2) {
        vector<int> sons;
        for(auto u : tree2[v]) 
            sons.pb(dp2[u]);
        sort(all(sons));
        if(hashes.find(sons) == hashes.end()) {
            hashes[sons] = cnt;
            cnt++;
            dp2[v] = hashes[sons];
        }
        else {
            dp2[v] = hashes[sons];
        }
    }

    if (dp1[r1] == dp2[r2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    

    return 0;
}
