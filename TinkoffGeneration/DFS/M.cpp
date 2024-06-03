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
// #define scan_array(_v) for(int i=0;i<(_v).size();i++){cin >> (_v)[i];}
#define fr first
#define sc second
#define pb push_back

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 1e5 + 19;

vector<pair<int, int>> gen_words;
vector<int> order;
vector<int> used(N, 0);

void dfs(int v, vector<int> g[N]) {
    used[v] = 1;
    for(auto u : g[v]){
        if (!used[u])
            dfs(u, g);
    }
    order.push_back(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y; 
        cin >> x >> y;
        gen_words.pb({x, y});
    }

    int l = 0;
    int r = m + 1;

    while(r - l > 0){
        int mid = (l + r) / 2;
        bool flag = true;

        vector<int> graph[N];
        set<pair<int, int>> ord;
        for(int i = 0; i < mid; i++){
            graph[gen_words[i].fr].pb(gen_words[i].sc);
            ord.insert(gen_words[i]);
        }

        for (int i = 1; i <= n; i++)
            if(!used[i])
                dfs(i, graph);
        reverse(all(order));
        
        /*
        cout << mid << ": " << r << " " << l << endl;
        print_array(order);
        for(auto &x : ord){
            cout << "( " << x.fr << " " << x.sc << " ) ";
        }
        cout << endl;
        */
        

        for (int i = 0; i < n - 1; i++)
        {
            if (ord.count({order[i], order[i + 1]}) < 1){
                flag = false;
                break;
            }
        }

        if(flag){
            r = mid;
        }
        else{
            l = mid + 1;
        }

        flag = true;
        order.clear();
        used.assign(n + 1, 0);
    }

    if (l == m + 1)
        cout << -1 << endl;
    else
        cout << l << endl;

    return 0;
}
