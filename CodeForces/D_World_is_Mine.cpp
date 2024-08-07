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
        int dp[n+1][n+1]{}, a[n+1], mp[n+1]{};
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = INT_MIN;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= (n+1)>>1; j++) {
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                if(dp[i-1][j] >= mp[i]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] - mp[i]);
                }
            }
        }
        for(int k = 0; k <= n; k++) {
            if(dp[n][k] >= 0) {
                cout << k << endl;
                break;
            }
        }

    }
    return 0;
}
