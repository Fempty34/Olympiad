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
const int MOD = 1e9 + 7;
const int N = 5*1e5 + 19;


mt19937 rnd(time(NULL));

//a <= a, b < MOD
int add_fast(int a, int b) {
    if (a + b < MOD) return a + b;
    else return a + b - MOD;
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
    return (a * 1ll * b) % MOD;
}

// Hash trees
vector<int> g[N];
map<vector<int>, int> hashes;

int getHash(vector<int> values) {
    if(hashes.find(values) != hashes.end()) return hash(values);
    hashes[values] = hashes.size();
    return hashes[values];
}

int dfs(int v, int p) {
    vector<int> values
    for(int u : g[v]) {
        if(u == p) continue;
        values.pb(dfs(u, v));
    }
    sort(values);
    return getHash(values);
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    


    
    

    return 0;
}
