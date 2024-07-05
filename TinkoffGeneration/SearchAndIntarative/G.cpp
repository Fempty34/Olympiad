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

int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans;
    return ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;

    vector<int> a(n);
    vector<int> pref_sum; pref_sum.pb(0);
    set<pair<int, int>> banned;

    for(int i = 0; i < n; i++) {
        int l = i + 1, r = i + 1;
        while(banned.find({l, r}) != banned.end()) {l--;}
        int s = ask(l, r);
        int banned_l, banned_r;
        cin >> banned_l >> banned_r;
        banned.insert({banned_l, banned_r});
        //cout << i << ": " << l << " " << pref_sum[l - 1] << endl;
        a[i] = s - (pref_sum[r - 1] - pref_sum[l - 1]);
        pref_sum.pb(pref_sum[i] + a[i]);
    }

    cout << "!" << endl;
    qfor(n) {
        cout << a[i] << " ";
    }
    

    return 0;
}
