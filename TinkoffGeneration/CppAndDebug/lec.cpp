// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2")


#include <bits/stdc++.h>
#include <cmath>

#include <ext/pb_ds/assoc_container.h>
#include <ext/pb_ds/tree_policy.h>

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define D_GLIBCXX_DEBUG
#define all(a) a.begin(), a.end()
#define int long long
#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define qfor(_n) for(int i=0;i<_n;i++)
#define fr first
#define sc second
#define pb push_back
#define debug(x) cerr << (#x) << ": " << (x) << endl

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

mt19937 rnd(197);


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> a = {1, 6, 445, 34};
    vector<int> b = {2, 3, 4, 9};
    vector<int> c(a.size() + b.size());
    merge(all(a), all(b), c.begin());
    print_array(c);

    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    sort(all(x), [] (pair<int, int> a, pair<int, int> b) -> bool{
        return a.sc < b.sc;
    });

    tuple<int, int, int> er;
    int x = ger<1>(er);
    
    shuffle(all(a));
    for(auto x : a) 
        cout << x << " ";
    cout << endl;

    int k  = 100;
    debug(k);



    return 0;
}
