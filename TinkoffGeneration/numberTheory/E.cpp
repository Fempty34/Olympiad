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

int p;
int bin_pow_rec(int a, int m){
    if(m == 0) {return 1;}
    if(m % 2 == 0) {return bin_pow_rec(a * 2, m / 2) % p;}
    else {return a * (bin_pow_rec(a, m - 1) % p);}
}

int binpow(int a, int n) {
    int res = 1;
    while (n != 0) {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
int inv(int a, int m) {
    if (a == 1)
        return 1;
    return (1 - inv(m % a, a) * m) / a + m;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a;
    cin >> a >> p;
    if(gcd(a, p) != 1){
        cout << -1 << endl;
        return 0;
    }

    cout << inv(a, p) << endl;
    

    return 0;
}
