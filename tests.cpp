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

    set<pair<int, int>> s;
	s.insert({2, 4});
	s.insert({2, 2});
	s.insert({3, 4});
	s.insert({1, 2});

	pair<int, int> sub = *(--s.lower_bound({2, INF}));
	//auto it = s.lower_bound({2, 0, 0});
	cout << sub.fr << " " << sub.sc << endl;
    
    
    

    return 0;
}
