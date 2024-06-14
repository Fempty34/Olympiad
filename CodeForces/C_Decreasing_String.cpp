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

    int t;
    cin >> t;
    while(t--){
        string s;
        int pos;
        cin >> s >> pos;
        pos--;
        
        int n = s.size();
        vector <char> st;
        bool flag = pos < n;
        s += '%';
        
        for (auto c : s) {
            while (!flag && st.size() > 0 && st.back() > c) {
                pos -= n;
                --n;
                st.pop_back();
                
                if(pos < n) 
                    flag = true;
            }
            st.push_back(c);
        }
        
        cout << st[pos];
    }
    
    
    

    return 0;
}
