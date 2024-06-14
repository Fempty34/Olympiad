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
//#define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
//#define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int exented_gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = exented_gcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b)*y1;
    
    return g;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}




signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int a, b, n, m;
        cin >> a >> b >> n >> m;

        if((b - a) % gcd(n, -m) != 0){
            cout << "NO" << endl;
            continue;
        }

        int x = 0, y = 0;
        exented_gcd(n, m, x, y);
        


        cout << "YES " <<((a + n * ((b - a)) * x) % lcm(n, m) + lcm(n, m)) % (lcm(n, m)) << " " << lcm(n, m) << endl;

    }

    

    return 0;
}
