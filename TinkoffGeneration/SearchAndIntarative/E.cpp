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
const double EPS = 0.00000001;

mt19937 rnd(197);
vector<vector<int>> offices;


double f(double x, double y, double z) {
    //return sqrt(x*x + y*y + z*z);
    double result = -1;
    for(auto office : offices) {
        double dx = x - (double)office[0];
        double dy = y - (double)office[1];
        double dz = z - (double)office[2];
        result = max(sqrt(dx*dx + dy*dy + dz*dz), result);
    }

    return result;
} 


double findZ(double x, double y) {
    double l = -10000, r = 10000;
    while (r - l > EPS) {
        double m1 = (2*l + r) / 3;
        double m2 = (2*r + l) / 3;

        if(f(x, y, m1) < f(x, y, m2)) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    return (l + r) / 2;
}

double findY(double x) {
    double l = -10000, r = 10000;
    while (r - l > EPS) {
        double m1 = (2*l + r) / 3;
        double m2 = (2*r + l) / 3;

        double z1 = findZ(x, m1);
        double z2 = findZ(x, m2);

        if(f(x, m1, z1) < f(x, m2, z2)) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    return (l + r) / 2;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    qfor(n) {
        int x, y, z;
        cin >> x >> y >> z;
        offices.pb({x, y, z});
    }

    double l = -10000, r = 10000;
    while (r - l > EPS) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;
        if (findY(m1) < findY(m2)) 
            r = m2;
        else
            l = m1;
    }
    double ans_x = (r + l) / 2;
    double ans_y = findY((l + r) / 2);
    double ans_z = findZ(ans_x, ans_y);

    cout << ans_x << " " << ans_y << " " << ans_z << endl;

    return 0;
}
