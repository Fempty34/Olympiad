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

mt19937 rnd(197);
int p, q;

int get_hash(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans * p + (s[i] - 'a') + 97) % q;
    return ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> p >> q;

    map<int, string> hash_to_str;
    while (true)
    {
        string s = "";
        for (int i = 0; i < 25; i++) s += char('a' + (int)rnd() % 26);
        int hash = get_hash(s);
        if (hash_to_str.find(hash) != hash_to_str.end()){
            cout << s << endl << hash_to_str.find(hash)->second << endl;
            break;
        }
        else{ hash_to_str[hash] = s; }
    }

    return 0;
}
