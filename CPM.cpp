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

struct Segtree
{
    int lb, rb;
    int gcd = 0;
    Segtree *l = 0, *r = 0;

    Segtree(int lb, int rb) : lb(lb), rb(rb){
        if(lb + 1 < rb){
            int t = (lb + rb) / 2;
            l = new Segtree(lb, t);
            r = new Segtree(t, rb);
        }
    }

    void add(int k, int v){
        if(l){
            if(k < l->rb)
                l->add(k, v);
            else
                r->add(k, v);
        }
    }

    int get(int lq, int rq){
        if(lb >= lq && rq <= rb)
            return 0;
        if(max(lb, lq) >= min(rb, rq))
            return -1;
        
        return -1;
    }

};



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> a((int)8*1e5);

    int n, q;
    cin >> n;

    Segtree s(0, n);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        s.add(i, x);
    }
    
    cin >> q;

    
    return 0;
}