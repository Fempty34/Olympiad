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

vector<int> a;

bool check(int C){
    int s = 0;
    for(auto x : a){
        s += C / x + 1;
    }
    return s <= C;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        a.resize(n);
        scan_array(a);

        int l = 0;
        int r = 1e9 + 1;

        while(r > l){
            int m = (l + r) / 2;
            
            if(check(m)){
                r = m;
            }else{
                l = m + 1;
            }
        }

        if(l < 1e9){
            vector<int> ans;
            for(auto x : a){
                ans.push_back(l / x + 1);
            }
            print_array(ans);
        }
        else{
            cout << -1 << '\n';
        }
        a.clear();
    }  

    return 0;
}
