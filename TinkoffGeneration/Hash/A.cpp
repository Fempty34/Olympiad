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
const int N = 5*1e5 + 19;
const int k = 37;
mt19937 rnd;




signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s; int n; n = s.size();
    

        
    vector<ll> p(n + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = (p[i - 1] * k) % MOD;

    vector<ll> h(n + 1, 0);
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * k + s[i - 1] - 'a' + 1) % MOD;


    int m; cin >> m;
    while(m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (((h[b] - h[a - 1] * p[b - a + 1]) % MOD + MOD) % MOD ==
         ((h[d] - h[c - 1] * p[d - c + 1]) % MOD + MOD) % MOD) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    
    

    return 0;
}
