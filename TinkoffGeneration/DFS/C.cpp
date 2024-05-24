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
// #define print_array(_v) for(int i=0;i<(_v).size();++i){cout<<(_v)[i]<<' ';}cout<<endl;
// #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 1e5 + 19;

int used[N];
vector<int> g[N];
vector<int> order;

void top_sort(int v)
{
    used[v] = 1;
    for (auto u : g[v])
    {
        if (!used[u])
        {
            top_sort(u);
        }
    }
    order.pb(v);
}

int used2[N];
int componets[N];
vector<int> reverse_g[N];

void cond_sort(int v, int comp)
{
    used2[v] = 1;
    componets[v] = comp;
    for (auto u : reverse_g[v])
    {
        if (!used2[u])
        {
            cond_sort(u, comp);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        g[v].pb(u);
        reverse_g[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            top_sort(i);
        }
    }

    reverse(all(order));

    int current_componet = 1;
    for (auto v : order)
    {
        if (!used2[v])
        {
            cond_sort(v, current_componet);
            current_componet++;
        }
    }

    cout << current_componet - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << componets[i] << " ";
    }

    return 0;
}