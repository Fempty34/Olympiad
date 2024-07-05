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

vector<int> a; int n, k;
bool check(int x) {
    //cout << "Case: " << x << endl;
    //print_array(b);
    vector<int> pref_sum;
    vector<int> min_pref_sum;
    pref_sum.pb(0);
    min_pref_sum.pb(pref_sum[0]);
    qfor(n) {
        if (a[i] >= x)
            pref_sum.pb(pref_sum[i] + 1);
        else
            pref_sum.pb(pref_sum[i] - 1);
        min_pref_sum.pb(min(min_pref_sum[i], pref_sum[i + 1]));
    }
    //print_array(pref_sum);
    //print_array(min_pref_sum);
    for(int i = k; i <= n; i++) {
        if (pref_sum[i] - min_pref_sum[i - k] > 0){
            //cout << "True" << endl;
            return true;
        }    
    }
    //cout << "False" << endl;
    return false;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    qfor(n){
        cin >> a[i];
    }
    int l = 1;
    int r = *max_element(all(a)) + 1;

    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    //cout << r << " " << l << endl;
    cout << l << endl;

    return 0;
}
