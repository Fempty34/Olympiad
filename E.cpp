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

mt19937 rnd;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; int k; cin >> n; cin >> k;
        vector<int> v(n);
        scan_array(v);

        map<int, vector<int>> m;
        for(int i = 0; i < n; i++)
            m[v[i] % k].pb(v[i]);
        

        int cnt = 0, ans = 0;
        for(auto p : m) {
            int os = p.fr;
            //cout << os << ": ";
            //print_array(p.sc);
            vector<int> elements = p.sc;
            sort(all(elements));
            if (elements.size() % 2 != 0) cnt++;
            
            vector<int> sub;

            for(int i = 0; i + 1 < elements.size(); i += 2) {
                sub.push_back(abs(elements[i] - elements[i + 1]) / k);
            }
            sort(all(sub));
            print_array(sub);
            for(int i = 0; i < elements.size() / 2; i++) {ans += sub[i];}

            

        }
        if(cnt > 1) cout << -1 << endl;
        else cout << ans << endl;
    }
    
    
    

    return 0;
}
