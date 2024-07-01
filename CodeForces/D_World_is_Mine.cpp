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

mt19937 rnd(197);
vector<int> a;

bool check(int k) {
    int cnt = 0; int last = -1; int index = 0;
    while(cnt != k && index < n) {
        if(a[index] != last){
            cnt++;
            last = a[index];
        }
        index++;
    }
    while(a[index] == last && index < n) index++;

    return k >= n - index - 1;
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        a.resize(n);
        scan_array(a);
        sort(all(a));

        int l = 0;
        int r = n;
        while(r > l) {
            int m = (l + r) / 2;
            if(check(r)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        cout << l << '\n';
    }
    
    

    return 0;
}
