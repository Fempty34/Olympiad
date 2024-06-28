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
const int N = 30;
const int CNT_TESTS = 50;

mt19937 rnd(197);

int lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    int lcs[n + 1][m + 1];

    for(int i = 0; i <= n; i++) 
        for (int j = 0; j <= m; j++)
            lcs[i][j] = 0;
        
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
        
    }

    return lcs[n][m];
}

string generate_string(int length){
    string s = "";
    for(int i = 0; i < length; i++){
        int temp = rnd() % 50 + 1;
        if(temp >= 25) s += "1";
        else s += "0";
    }
    return s;
}

int sum(vector<int> v) {
    int res = 0;
    for(int i = 0; i < v.size(); i++) res += v[i];
    return res;
}

double sum(vector<double> v) {
    double res = 0;
    for(int i = 0; i < v.size(); i++) res += v[i];
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<double> ans;
    int length = 500;

    int u = CNT_TESTS; vector<double> lcs_vec;
    while(u--) {
        string a = generate_string(length);
        string b = generate_string(length);
        //cout << t << ": " << a << " " << b << " " << (double)lcs(a, b) / (double)length << endl;
        lcs_vec.pb((double)lcs(a, b) / (double)length);
    }
    
    ans.pb((double)sum(lcs_vec) / (double)CNT_TESTS);

    cout << ans[0] << endl;

    return 0;
}
