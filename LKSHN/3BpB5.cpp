//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

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

int INF = 1e9 + 1;
const int MOD = 1e9;
//const int N = 1e5 + 19;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x - k);
    }
    vector<int> pref_sum(n + 1);

    pref_sum[0] = 0;

    for (int i = 0; i < n; i++)
        pref_sum[i + 1] = pref_sum[i] + v[i];

    int ans = 0;

    /*
    multiset<int> sub;
    //print_array(pref_sum);
    for(int i = 0; i <= n; i++){
        //cout << pref_sum[i] << " " << distance(sub.begin(), sub.upper_bound(pref_sum[i])) << endl;
        ans += distance(sub.begin(), sub.upper_bound(pref_sum[i]));
        sub.insert(pref_sum[i]);  
    }
    */
    
    cout << ans << endl;
    return 0;
}