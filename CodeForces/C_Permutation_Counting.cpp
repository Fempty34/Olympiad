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
const int N = 1e5 + 19;



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t; cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> cards(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> cards[i];
        }
        

        sort(all(cards));

        for(int i = 1; i <= n;i++){
			if(i != n && (cards[i+1] - cards[i]) * i <= k) k -= (cards[i+1] - cards[i]) * i;
			else{
				cout << (cards[i] + k / i) * n + k % i - i+1 <<endl;
				break;
			}
		}
    }
    return 0;
}
