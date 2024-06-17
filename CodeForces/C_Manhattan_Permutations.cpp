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

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        if(k % 2 != 0){
            cout << "NO" << endl;
            continue;
        }

        int l = 1;
        int r = n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }


        while(l <= r){
            if(k >= 2 * (r - l)) {
                swap(p[l], p[r]);
                k -= 2 * (r - l);
                l++;
                r--;
            }
            else{
                r--;
            }
        }

        if(k){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        
    }
    
    
    

    return 0;
}
