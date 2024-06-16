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

vector<string> getSubStrings(string s)
{
    vector<string> us;

    for (int i = 0; i < s.size(); ++i) {
        string ss = "";
        for (int j = i; j < s.size(); ++j) {
            ss = ss + s[j];
            us.pb(ss);
        }
    }
    

    return us;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    vector<string> a = getSubStrings(s);
    map<int, vector<string>> size_to_strings;
    for (int i = 0; i < a.size(); ++i) {
        size_to_strings[a[i].size()].pb(a[i]);
    }
    int ans = 0;

    for(auto x : size_to_strings){
        int sz = x.fr;
        vector<string> strings = x.sc;
        sort(all(strings));
        int n = strings.size();
        vector<int> dp(n);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (strings[i] == strings[i + 1])
                dp[i] = dp[i + 1];
            else
                dp[i] = n - i - 1;
            
        }
        for(auto x : dp){
            ans += x;
        }
    }
    
    cout << ans << endl;
    

    return 0;
}
