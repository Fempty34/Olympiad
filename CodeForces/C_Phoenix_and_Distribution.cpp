// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define all(a) a.begin(), a.end()
//#define int long long
#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 2*1e5 + 19;


string s, t;
int nxt[N][26];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c; cin >> c;
    while(c--){
        cin >> s >> t;
        for(int i = 0; i < s.size() + 5; ++i)
            for(int j = 0; j < 26; ++j)
                nxt[i][j] = INF;
    	
        for(int i = int(s.size()) - 1; i >= 0; --i){
            for(int j = 0; j < 26; ++j)
                nxt[i][j] = nxt[i + 1][j];
            nxt[i][s[i] - 'a'] = i;
        }    
    
        int res = 1, pos = 0;
        for(int i = 0; i < t.size(); ++i){
            if(pos == s.size()){
                pos = 0;
                ++res;
            }
            if(nxt[pos][t[i] - 'a'] == INF){
                pos = 0; 
                ++res;
    		}
    		if(nxt[pos][t[i] - 'a'] == INF && pos == 0){
                res = INF;
                break;
            }    
            pos = nxt[pos][t[i] - 'a'] + 1;
            
        }
    
        if(res >= INF) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
