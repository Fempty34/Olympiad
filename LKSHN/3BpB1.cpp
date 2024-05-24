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

int n, x, y;
vector<int> l;

bool checker(int k){
    vector<int> sub(n, k*y);
    for (int i = 0; i < n; i++)
    {
        if (sub[i] < l[i]){
            k -= ceil((double)(l[i] - sub[i]) / (double)(x - y));
        }
        if(k < 0)
            return false;
    }
    return true;
}
    
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x >> y;
    l.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    int l = 0, r = 1e9;
    
    while(l < r){
        int mid = (l + r) / 2;
        
        if (checker(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(checker(l))
        cout << l << endl;
    else
        cout << r << endl;



    
    return 0;
}