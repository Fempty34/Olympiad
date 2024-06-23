// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define all(a) a.begin(), a.end()
//#define int long long
#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int N = 1e5 + 19;
const int b = 37;

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
    for (int i = 1; i <= n; i++) pows[i] = (pows[i - 1] * b) % MOD;
    for (int i = 1; i <= n; i++) t_hash[i] = (t_hash[i - 1] * b + (t[i - 1] - 'a' + 1)) % MOD;
    for (int i = 1; i <= m; i++) p_hash[i] = (p_hash[i - 1] * b + (p[i - 1] - 'a' + 1)) % MOD;

    int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;

	if(get_t_hash(l1, r1) == get_p_hash(l2, r2)) cout << "YES";
	else cout << "NO";


    return 0;
}
