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
        int n;
        cin >> n;
        string s;
        cin >> s;

        string sub;
        sub += s[0];
        sub += s[1];
        int ans = 0;

        for (int i = 2; i < n; i++)
        {
            if(sub[sub.size() - 2] == 'p' && sub[sub.size() - 1] == 'i' && s[i] == 'e')ans++;
            else if(sub[sub.size() - 2] == 'm' && sub[sub.size() - 1] == 'a' && s[i] == 'p')ans++;
            else sub += s[i];
            cout << sub << endl;
        }
        cout << ans << endl;
    }

    
    
    

    return 0;
}
