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

vector<int> v;
vector<int> p;

bool check(int k) {
    vector<int> sub = v;
    qfor(k - 1)
        sub[p[i] - 1] = 0;
    
    sort(all(sub));
    reverse(all(sub));

    
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    v.resize(n); p.resize(n);
    scan_array(v); scan_array(p);

    int l = 0;
    int r = *max_element(all(v)) * n;

    while(l < r) {
        int m = (l + r) / 2;
        
    }

    

    return 0;
}
