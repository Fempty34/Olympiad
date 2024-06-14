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

int INF = 1e18 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;


int dp[N][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> c(n);
    scan_array(c);

    vector<string> strs(n);
    vector<string> strs_rev(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs[i] = s;
        reverse(all(s));
        strs_rev[i] = s;
        dp[i][0] = INF;
        dp[i][1] = INF;
    }
    
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 1; i < n; ++i) {
        if(strs[i] >= strs[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if(strs[i] >= strs_rev[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if(strs_rev[i] >= strs[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if(strs_rev[i] >= strs_rev[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }

    if(dp[n - 1][1] == INF && dp[n - 1][0] == INF)
	    cout << "-1" << endl;
    else
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;

    return 0;
}
