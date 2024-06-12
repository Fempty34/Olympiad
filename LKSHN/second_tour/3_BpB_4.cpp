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


int dp[N][N][10][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    string a;
    cin >> a;
    string b;
    cin >> b;

    if(a[0] == b[0]){
        for (int c = 1; c <= k; c++)
        {
            for(int i = 0; i < n; i++){
                dp[i][0][0] = 1;
                dp[i][0][1] = 1;
            }
            for(int j = 0; j < m; i++){
                dp[0][j][0] = 1;
                dp[0][j][1] = 1;
            }
        }
    }

    for (int c = 1; c <= k; ++c) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[i][j][c][0] = max(dp[i-1][j-1][c][0] + 1, max(dp[i - 1][j - 1][c - 1][1] + 1, dp[i][j][c][0]));
                    dp[i][j][c][1] = max(dp[i][j][c][0], max(dp[i - 1][j][c][1], dp[i][j - 1][c][1]));
                }
                else {
                    if (i == 0) {
                        dp[i][j][c][1] = dp[i][j - 1][c][1];
                    }
                    else if (j == 0) {
                        dp[i][j][c][1] = dp[i - 1][j][c][1];
                    }
                    else {
                        dp[i][j][c][1] = max(dp[i - 1][j][c][1], dp[i][j - 1][c][1]);
                    }
                }
            }
        }
    }
    
    
    cout << max(dp[n - 1][m - 1][k][0], dp[n - 1][m - 1][k][1]);

    return 0;
}
