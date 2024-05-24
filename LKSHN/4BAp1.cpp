#include<bits/stdc++.h>

using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
mt19937 rnd(157);
int INF = 2e9;

#define all(a) a.begin(), a.end()
//#define int long long

vector<vector<int>> g;
vector<int> pow1;
vector<int> color;
vector<vector<int>> max3;
vector<int> pow2;

void merge1(int c, int u) {
    for(int i = 0; i < 3; i++) {
        int h = min(max3[u][i], c);
        max3[u][i] = max(max3[u][i], c);
        c = h;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    g.resize(n);
    pow1.resize(n, 0);
    pow2.resize(n, 0);
    color.resize(n, -1);
    max3.resize(n, vector<int> (3, -1));
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        pow1[v]++;
        pow1[u]++;
    }
    set<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        if(pow1[i] <= 2) {
            q.insert({0, i});
            color[i] = 0;
        }
    }
    int ans = 0;
    while(!q.empty()) {
        auto[c, v] = *q.begin();
        q.erase(q.begin());
        for(int u : g[v]) {
            merge1(c, u);
            pow2[u]++;
            if(color[u] == -1 && pow1[u] - pow2[u] <= 1) {
                q.insert({max3[u][2] + 1, u});
                color[u] = max3[u][2] + 1;
                ans = max(ans, color[u]);
            }
        }
    }
    max3.assign(n, vector<int> (3, -1));
    for(int i = 0; i < n; i++) {
        for(int j : g[i]) {
            merge1(color[j], i);
        }
        ans = max(ans, max3[i][2] + 1);
    }

    // for(auto el : color) {
    //     cout << el << ' ';
    // }
    // cout << endl;
    if(ans >= d) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}