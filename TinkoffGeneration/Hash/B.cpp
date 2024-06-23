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
const int N = 1e5 + 19;
const int b = 59;

mt19937 rnd;

ll pows[N];
ll t_hash[N];
ll p_hash[N];


ll get_t_hash(int l, int r) {
    return ((t_hash[r + 1] - t_hash[l] * pows[r - l + 1]) % MOD + MOD) % MOD; 
}

ll get_p_hash(int l, int r) {
    return ((p_hash[r + 1] - p_hash[l] * pows[r - l + 1]) % MOD + MOD) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string p, t;
    cin >> p >> t;
    int n = t.size();
    int m = p.size();

    pows[0] = 1;
    for (int i = 1; i <= max(m, n); i++) pows[i] = (pows[i - 1] * b) % MOD;
    for (int i = 1; i <= n; i++) t_hash[i] = (t_hash[i - 1] * b + (t[i - 1] - 'A' + 1)) % MOD;
    for (int i = 1; i <= m; i++) p_hash[i] = (p_hash[i - 1] * b + (p[i - 1] - 'A' + 1)) % MOD;

    vector<int> ans;
    for(int i = 0; i < n - m + 1; i++) {
        int l = i; int r = i + m;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(get_t_hash(i, mid) == get_p_hash(0, mid - i)) l = mid;
            else r = mid;
        }
        //cout << i << " " << r << " " << l << endl;

        int diff_index = -1;
        if(t[l] != p[l - i]) diff_index = l - i;
        else diff_index = r - i;

        //cout << i << " " << diff_index << endl;

        int l1 = diff_index + i + 1; int r1 = i + m - 1;
        int l2 = diff_index + 1; int r2 = m; 

        //for(int u = diff_index + 1; u <= m; u++) cout << p[u];
        //cout << endl;

        //for(int u = diff_index + i + 1; u < i + m; u++) cout << t[u];
        //cout << endl;

        if (diff_index == m) ans.pb(i + 1);
        else if(get_t_hash(diff_index + i + 1, i + m - 1) == get_p_hash(diff_index + 1, m - 1)) ans.pb(i + 1);
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    

    return 0;
}
