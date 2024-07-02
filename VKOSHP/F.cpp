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
    vector<int> a(n), b(n);
    scan_array(a);
    scan_array(b);

    reverse(all(a));
    reverse(all(b));
    vector<int> type(n, 0);

    qfor(n) {
        if (a[i] <= b[i]){
            b[i] = a[i];
            type[i] = 1;
        }
    }   
    //b[0] = a[0];
    //print_array(b);
    //print_array(type);

    vector<int> pref_sum_b;
    pref_sum_b.pb(0);
    for (int i = 0; i < n; ++i)
        pref_sum_b.pb(pref_sum_b[i] + b[i]);    
    //print_array(pref_sum_b);
    int ans;
    if(type[n - 1] == 1)
        ans = pref_sum_b[n];
    else
        ans = pref_sum_b[n] - b[n - 1] + a[n - 1];
    

    for (int i = n - 1; i >= n - m; i--){
        if(type[i] == 1) {
            ans = min(ans, pref_sum_b[i + 1]);
        }
        else {
            ans = min(ans, pref_sum_b[i + 1] - b[i] + a[i]);
        }
    }

    //if(ans == INF || m == n) cout << a[0] << endl;
    cout << ans << endl;

    /*
        vector<int> dp(n);
        dp[0] = a[0];
        for (int i = 1; i < n; i++)
            dp[i] = min(dp[i - 1] + a[i], a[i] + pref_sum_b[i]);
        
        int ans = dp[n - 1];
        for (int i = n - 1; i >= n - m; i--)
            ans = min(ans, dp[i]);
        
        cout << ans << endl;
    */
    
    
    

    return 0;
}
