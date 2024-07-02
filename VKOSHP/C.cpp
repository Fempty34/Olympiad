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
#define qfor(_n) for(int i=0;i<_n;i++)
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

mt19937 rnd(197);
int dp[N][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string path; cin >> path;
    int a, b; cin >> a >> b;
    int n = path.size();
    int ans = 0;
    vector<char> s(n);
    qfor(n) s[i] = path[i];

    char first_letter = '4';
    for(int i = 1; i < n; i++) {
        if (s[i] == '?' && s[i - 1] != '?') 
            s[i] = s[i - 1];
        if (s[i] != '?' && first_letter == '4')
            first_letter = s[i];
    }

    for (int i = 0; i < n; i++) {
        if(s[i] != '?') break;
        else s[i] = first_letter;
    }

    if (first_letter == '4') {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') ans += b;
        else if (s[i - 1] == '0' && s[i] == '1') ans += a;
    }

    cout << ans << endl;

    return 0;
}
