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

vector<int> z_function(string s){
    vector<int> dp(s.size());
    dp[0] = s.size();
    int l = 0, r = 1;
    for (int i = 1; i < n; i++)
    {
        if(l < r)
            dp[i] = min(dp[i - l], r - i);
        while (i + dp[i] < s.size() && s[i] == s[dp[i]]) dp[i]++;
        if(i + dp[i] > r){
            r = i + dp[i];
            l = i;
        } 
    }
    return dp;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    cin >> a;


    
    

    return 0;
}
