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

mt19937 rnd(197);

double f(double x) {
    return x + 1;
}

double fn(double x, double y) {
    return 2*x*x + y*y/5 + 2*x;
}

double findY(double x) {
    double l = -100, r = 100;
    qfor(100) {
        double m1 = (2*l + r) / 3;
        double m2 = (2*r + l) / 3;

        if(fn(x, m1) < fn(x, m2)) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    return (l + r) / 2;
}

double findX() {
    double l = -100, r = 100;
    qfor(100) {
        double m1 = (2*l + r) / 3;
        double m2 = (2*r + l) / 3;

        double y1 = findY(m1);
        double y2 = findY(m2);

        if(f(m1, y1) < f(m2, y2)) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    return (l + r) / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //log1.5((r - l) / EPS);
    double l, r;
    const double EPS = 0.00001;
    while(r - l > EPS) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;
        if (f(m1) < f(m2)) 
            l = m1;
        else
            r = m2;
    }

    qfor(100) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;
        if (f(m1) < f(m2)) 
            l = m1;
        else
            r = m2;
    }

    //Вложенный тернаркник


    return 0;
}
