#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

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

const int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 1e5 + 3;

map<int, int> m_map;
map<int, int> mult;
vector<int> m_dividers;

vector<int> getPrimeDividers(int n) {
    vector<int> ans;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            int p = i;
            while (n % p == 0) {
                n /= p;
                ans.push_back(p);
            }
        }
    }
    if (n > 1)
        ans.push_back(n);
    
    return ans;
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
    
    vector<int> primes;
    for(int i = 2; i <= n; i++){
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool check() {
    for (auto div : m_dividers) {
        if (m_map[div] > mult[div]) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> primes = sieve(N);
    for(auto u: getPrimeDividers(m)){
        m_dividers.push_back(u);
        m_map[u]++;
    }

    int ans = 0;
    int r = 0;
    for(int l = 0; l < n; l++){
        while(!check()){
            if(r == n)
                break;
            else{
                int sub = v[r];
                for(auto u : primes) {
                    while (sub % u == 0) {
                        mult[u]++;
                        sub /= u;
                    }
                }
                if (sub != 1)
                    mult[sub]++;
                r++;
            }
        }

        if (!check())
            break;

        ans += n - r + 1;
        int sub = v[l];
        for (auto u : primes) {
            while (sub % u == 0) {
                mult[u]--;
                sub /= u;
            }
        }
        if (sub != 1)
            mult[sub]--;
    }

    cout << ans << endl;
    return 0;
}
