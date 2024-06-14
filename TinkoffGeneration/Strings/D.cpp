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
//#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
//#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){ 
        int j = dp[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = dp[j - 1];
        }
        if(s[i] == s[j])j++;
        dp[i] = j;
    }
    return dp;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    
    vector<int> ans = prefix_function(s + "#" + t + t);

    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == t.size()){
            cout << i - t.size() - t.size()<< " ";
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
