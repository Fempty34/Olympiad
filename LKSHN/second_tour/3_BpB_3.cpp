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

int n, x;
vector<vector<int>> tasks;

bool check(int k){
    vector<int> valid_tests;
    for (auto task : tasks){
        if(task[0] >= k)
            valid_tests.pb(task[1]);
    }
    sort(all(valid_tests));
    int time = 0; int cnt = 0;
    for(auto task : valid_tests){
        if(time < x){
            time += task;
            cnt++;
        }
    }
    if(time > x){cnt--;}

    if(cnt >= k)
        return true;
    else
        return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    
    for (int i = 1; i <= n; i++)
    {
        int p, q;
        cin >> p >> q;
        tasks.pb({p, q, i});
    }
    sort(all(tasks));
    reverse(all(tasks));

    int l = 0, r = n;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(check(m))
            l = m;
        else
            r = m;
    }
    if(check(r) && r <= n)
        l = r;


    cout << l << endl;
    cout << l << endl;

    vector<pair<int, int>> valid_tests;
    for (auto task : tasks){
        if(task[0] >= l)
            valid_tests.pb({task[1], task[2]});
        else
            break;
    }

    sort(all(valid_tests));
    for(int i = 0; i < l; i++){
        cout << valid_tests[i].sc << " ";
    }

    return 0;
}
