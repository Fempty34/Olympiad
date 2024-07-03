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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    set<string> keys;
    int flag = 0;
    qfor(n) {
        str s; cin >> s;
        keys.insert(s);
        flag += s.size();
    }
    vector<int> v;
    int cnt = 0;
    qfor(m) {
        string s; cin >> s; cnt += s.size();
        if (keys.find(s) != keys.end()) {
            keys.erase(s);
        } else {
            v.pb(s.size());
        }
    }

    sort(all(v));
    reverse(all(v));
    int index = 0;
    int d; cin >> d;    
    if (flag > d || keys.size() != 0) {cout << -1 << endl; return 0;}

    while(cnt > d) {
        cnt -= v[index];
        index++;
    }
    cout << index << endl;


    return 0;
}
