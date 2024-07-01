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
const int N = 500 + 19;
const int b1 = 57;
const int b2 = 53;

mt19937 rnd(197);

vector<string> table;
int h[N][N];
int pows1[N];
int pows2[N];

int get_subtable_hash(int x1, int x2, int y1, int y2) {
    return (h[x2][y2] - h[x2][y1] * pows2[y2 - y1 + 1] - h[x1][y2] * pows1[x2 - x1 + 1]
            + h[x1][y1] * pows2[y2 - y1 + 1] + h[x1][y1] * pows1[x2 - x1 + 1] - 
            h[x1][y1] * pows2[y2 - y1 + 1] * pows1[x2 - x1 + 1]) % MOD;
}

pair<int, int> checker(int i, int j, int mid) {
    map<int, pair<int, int>> squares_hashes;
    for(int i = 1; i <= min(n, m) - mid + 1; i++) {
        for(int j = 1; j <= min(n, m) - mid + 1; j++) {
            int hash1 = get_subtable_hash(i, i + mid - 1, i, i + mid - 1);
            int hash2 = get_subtable_hash(j, j + mid - 1, j, j + mid - 1);
            if (hash1 == hash2) {
                return 
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    qfor(n) {
        string s; cin >> s;
        table.pb(s);
    }

    pows1[0] = 1;
    for (int i = 1; i <= n; i++) pows1[i] = (pows1[i - 1] * b1) % MOD;
    pows2[0] = 1;
    for (int i = 1; i <= m; i++) pows2[i] = (pows2[i - 1] * b2) % MOD;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            h[i][j] = (h[i - 1][j]*b1 + h[i][j - 1]*b2 - h[i - 1][j - 1]*b1*b2 + (table[i - 1][j - 1] - 'a' + 1)) % MOD;
    

    int l = 0;
    int r = min(n, m);
    int x1, x2, y1, y2;
    while (l < r) {
        int mid = (l + r) / 2;
        
    }
    

    

    return 0;
}
