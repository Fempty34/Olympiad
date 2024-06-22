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
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;

        string a_temp, b_temp;
        cin >> a_temp >> b_temp;

        vector<int> a;
        vector<int> b;

        for(auto x : a_temp) {
            if(x == '0') a.pb(0);
            else a.pb(1);
        }

        for(auto x : b_temp) {
            if(x == '0') b.pb(0);
            else b.pb(1);
        }

        for (int i = 0; i < n - 2; i++)
            if(a[i] == a[i + 2] && a[i] == 0) b[i + 1] = 1;
        
        for (int i = 0; i < n - 2; i++)
            if(b[i] == b[i + 2] && b[i] == 1) a[i + 1] = 1;
        
        
        vector<int> pref_a;
        vector<int> pref_b;

        pref_a.pb(0);
        pref_b.pb(0);

        for (int i = 0; i < n; i++) pref_a.pb(pref_a[i] + a[i]);
        //for (int i = 0; i < n; i++) pref_b.pb(pref_b[i] + b[i]);

        //print_array(pref_a);
        int q; cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            

            //cout << a_temp[l] << " " << b[l + 1] << " " << endl;
            if(r - l >= 4){
                int ans = pref_a[r] - pref_a[l - 1];
                if(a_temp[l - 1] == '0' && a[l - 1] == 1) ans--;
                if(a_temp[r - 1] == '0' && a[r - 1] == 1) ans--;
                if(a_temp[l] == '0' && a[l] == 1 && b_temp[l - 1] == '0') ans--;
                if(a_temp[r - 2] == '0' && a[r - 2] == 1 && b_temp[r - 1] == '0') ans--;

                cout << ans << endl;
            }
            else if (r - l == 2){
                int ans = 0;
                if(a_temp[l - 1] == '1') ans++;
                if(a_temp[l]  == '1') ans++;
                if(a_temp[r - 1] == '1') ans++;

                if(b_temp[l - 1] == '1' && b_temp[r - 1] == '1' && a_temp[l] == '0') ans++;

                cout << ans << endl;
            }
            else if (r - l == 3){
                int ans = 0;
                vector<int> sub_a;
                vector<int> sub_b;


                for (int i = l - 1; i < r; i++)
                {
                    if(a_temp[i] == '0') sub_a.pb(0);
                    else sub_a.pb(1);

                    if(b_temp[i] == '0') sub_b.pb(0);
                    else sub_b.pb(1);
                }
                


                for(int i = 0; i < r - l - 1; i++){
                    if(sub_a[i] == sub_a[i + 2] && sub_a[i] == 0) sub_b[i + 1] = 1;
                }
                //print_array(sub_a);
                //print_array(sub_b);
                for(int i = 0; i < r - l - 1; i++){
                    if(sub_b[i] == sub_b[i + 2] && sub_b[i] == 1) sub_a[i + 1] = 1;
                }
                //print_array(sub_a);
                //print_array(sub_b);
                
                for(auto x: sub_a){
                    ans += x;
                }

                cout << ans << endl;
            }
            else {
                int ans = 0;
                for (int i = l - 1; i < r; i++)
                {
                    if(a_temp[i] == '1') ans++;
                }
                cout << ans << endl;
            }

        }

    }
    
    
    

    return 0;
}
