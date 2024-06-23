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

mt19937 rnd;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    scan_array(a);

    vector<int> pref_sum;
    pref_sum.pb(0);
    for (int i = 0; i < n; i++) pref_sum.pb(pref_sum[i] + a[i]);

    vector<int> suffix_sum(n + 1);
    suffix_sum[n] = 0;
    for (int i = n - 1; i >= 0; i--) suffix_sum[i] = suffix_sum[i + 1] + a[i];

    vector<int> cnt_suff_sums(n);
    cnt_suff_sums[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        cnt_suff_sums[i] = cnt_suff_sums[i + 1] + (suffix_sum[i + 1] == pref_sum.back() / 3);
    
    //print_array(suffix_sum);
    //print_array(cnt_suff_sums);

    if(pref_sum.back() % 3 != 0) {cout << 0 << endl; return 0;}

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if(pref_sum[i] != pref_sum.back() / 3) continue;
        ans += cnt_suff_sums[i];
    }
    
    cout << ans << endl;
    
    

    return 0;
}
