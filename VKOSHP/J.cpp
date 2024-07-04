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
#define qfor(_n) for(int i=0;i<_n;i++)
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

mt19937 rnd(197);


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    qfor(n) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(all(a));

    vector<int> pref_sum;
    pref_sum.pb(0);
    for(int i = 0; i < n; i++) pref_sum.pb(pref_sum[i] + a[i].fr);
    
    int ans = -1; int index = -1;
    qfor(n - m + 1) {
        if (ans == -1 || ans >= pref_sum[i + m] - pref_sum[i] - m * a[i].fr) {
            index = i;
            ans = pref_sum[i + m] - pref_sum[i] - m * a[i].fr;
        }
    }
    qfor(m) {
        cout << a[index + i].sc + 1 << " ";
    }

    return 0;
}
