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
const int N = 1e3;

mt19937 rnd(197);


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i ++ ) {
    	cin >> a[i];
    	s = max(s, a[i]);
    }
    vector<int> f(s + 1, s + 1);
    for (int i = 0; i < n; i ++ ) {
    	int b;
    	cin >> b;
    	f[a[i]] = min(f[a[i]], a[i] - b);
    }
    for (int i = 1; i <= s; i ++ ) {
    	f[i] = min(f[i], f[i - 1]);
    }
    vector<int> dp(s + 1);
    for (int i = 1; i <= s; i ++ ) {
    	if (f[i] <= i) {
    		dp[i] = dp[i - f[i]] + 1;
    	}
    }
 
    ll res = 0;
    while (m -- ) {
    	int k;
    	cin >> k;
    	if (k > s) {
    		int t = (k - s + f[s] - 1) / f[s];
    		k -= t * f[s];
    		res += t;
   		}
   		res += dp[k];
    }
    cout << res * 2 << endl;
    return 0;
}
