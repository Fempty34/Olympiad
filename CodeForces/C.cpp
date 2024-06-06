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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        scan_array(a);
        vector<int> b(n);
        scan_array(b);
        int m; cin >> m;
        vector<int> d(m);
        scan_array(d);

        
        map<int, int> m_a;
        map<int, int> m_b;
        map<int, int> m_d;

        for (int i = 0; i < n; i++)
        {
            m_a[a[i]]++;
            m_b[b[i]]++;
        }
        for (int i = 0; i < m; i++){
            m_d[d[i]]++;
        }

        for(auto u: m_b){
            int key = u.fr;
            int value = u.sc;
            m_b[key] = max((ll)0, value - m_a[key]);
        }

        for(auto u: m_b){
            int key = u.fr;
            int value = u.sc;
            if(value > 0){
                m_b[key] -= m_d[key];
            }
        }
        bool flag = true;
        for(auto u: m_b){
            int key = u.fr;
            int value = u.sc;
            if(value != 0){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }



    return 0;
}
