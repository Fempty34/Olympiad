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


int ask(int x) {
    cout << "? " << x + 1 << endl;
    int ans; cin >> ans;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;

    int l = -1, r = n - 1;
    while(r - l > 1) {
        int m = (l + r) / 2;
        int res1 = ask(m);
        int res2 = ask(m + 1);
        if ((m % 2 == 0 && res1 == res2) || (m % 2 == 1 && res1 != res2)) {
            l = m;
        } else {
            r = m;
        }
    }
    int ans = ask(r);
    cout << "! " << ans << endl; 
}
