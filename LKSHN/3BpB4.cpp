#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

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

const int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 2 * 1e5 + 3;

vector<int> g1[N];
vector<int> g2[N];

int col1[N];
int col2[N];

void dfs1(int v, int c) {
    col1[v] = c;
    for(auto u: g1[v]) {
        if(!col1[u])
            dfs1(u, c);
    }
}

int dfs2(int v, int c) {
    col2[v] = c;
    for(auto u: g2[v]) {
        if(!col2[u])
            dfs2(u, c);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, q;
    cin >> n >> p >> q;

    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    int c = 1;
    for (int i = 1; i <= n; i++) {
        if(!col1[i]) {
            dfs1(i, c);
            c++;
        }
    }

    c = 1;
    for (int i = 1; i <= n; i++) {
        if(!col2[i]) {
            dfs2(i, c);
            c++;
        }
    }
    map<pair<int, int>, int> m3;

    for(int i = 1; i <= n; i++) {
        m3[{col1[i], col2[i]}]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << m3[{col1[i], col2[i]}] << " ";
    }

    return 0;
}