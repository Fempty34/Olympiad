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

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> v(n * m, 0);
    v[p] = 1;
    for(int i = p; i <= n; i++) {
        if(v[i] == 1) {
            for(int j = 2; j <= m; j++) {
                if(v[i * j] == 0)
                    v[i * j] = 2;
            }
        }
        else if(v[i] == 2) {
            for(int j = 2; j <= m; j++) {
                if(v[i * j] == 0)
                    v[i * j] = 1;
            }
        }
    }
    
    int index = n;
    while(v[index] == 0) index++;
    
    if(v[index] == 1) {
        cout << "second" << endl;
    }
    else {
        cout << "first"  << endl;
    }

    return 0;
}
