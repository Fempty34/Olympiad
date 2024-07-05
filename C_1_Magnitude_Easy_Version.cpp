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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        scan_array(a);
        vector<pair<int, int>> dp(n + 1);
        dp[0] = {0, 0};
        for(int i = 0; i < n; i++) {
            dp[i + 1].fr = max({dp[i].fr + a[i], abs(dp[i].fr + a[i]), dp[i].sc + a[i],  abs(dp[i].sc + a[i])});
            dp[i + 1].sc = min({dp[i].sc + a[i], abs(dp[i].sc + a[i]), dp[i].fr + a[i], abs(dp[i].fr + a[i])});
        }
        //for(auto x : dp) {
        //    cout << x.fr << " " << x.sc << "   ";
        //}
        //cout << endl;
        cout << max({dp[n].fr, dp[n - 1].sc + a[n - 1], abs(dp[n - 1].sc + a[n - 1])}) << '\n';
    }
    
    

    return 0;
}
