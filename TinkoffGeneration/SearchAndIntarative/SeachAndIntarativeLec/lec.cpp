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

int queries = 0;
const int MAXQ = 30;
int ask(int x) {
    ++queries;
    assert(queries <= MAXQ);
    cout << "? " << x << endl;
    int res;
    cin >> res;
    
    return res;
}
int answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    
    

    return 0;
}