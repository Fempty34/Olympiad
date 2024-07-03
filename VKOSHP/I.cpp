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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    vector<int> left(n + 1);
    vector<int> right(n + 1);
    left[0] = 0;
    right[n] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (s[i - 1] == '0')
            left[i] = left[i - 1] + 1;
        else
            left[i] = left[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1')
            right[i] = right[i + 1] + 1;
        else
            right[i] = right[i + 1];
    }
    
    //print_array(left);
    //print_array(right);

    vector<int> answers;
    qfor(n + 1) {
        if(left[i] >= ceil((double)i / (double)2) && right[i] >= ceil((double)(n - i) / (double)2))
            answers.pb(i);
    }
    //print_array(answers);
    int ans = -1;
    for(int i : answers) {
        if (abs((double)n / 2 - (double)ans) > abs((double)n / 2 - (double)i) || ans == -1) 
            ans = i;
    }
    cout << ans << endl;
    

    return 0;
}
