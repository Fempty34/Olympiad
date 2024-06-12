// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 
 

int INF = 1e9 + 1;
const int MOD = 1e9;
const int N = 5*1e5 + 19;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> opened_chests;
    vector<int> closed_chests;
    vector<int> keys;

    for (int i = 0; i < n; i++)
    {
        int type, value;
        cin >> type >> value;

        if(type == 0)
            opened_chests.pb(value);
        else if(type == 1)
            closed_chests.pb(value);
        else
            keys.pb(value);
    }
    sort(all(opened_chests));
    reverse(all(opened_chests));

    sort(all(closed_chests));
    reverse(all(closed_chests));

    sort(all(keys));
    reverse(all(keys));

    ordered_set prefix_opened_chests;
    ordered_set prefix_closed_chests;
    ordered_set prefix_keys;

    prefix_opened_chests.insert(0);
    prefix_closed_chests.insert(0);
    prefix_keys.insert(0);

    for(int i = 0; i < opened_chests.size(); i++){
        prefix_opened_chests.insert(*prefix_opened_chests.find_by_order(i) + opened_chests[i]);
        //cout << *prefix_opened_chests.find_by_order(i) << " ";
    }
    //cout << *prefix_opened_chests.find_by_order(opened_chests.size()) << endl;

    for (int i = 0; i < closed_chests.size(); i++)
        prefix_closed_chests.insert(*prefix_closed_chests.find_by_order(i) + closed_chests[i]);
    
    for (int i = 0; i < keys.size(); i++)
        prefix_keys.insert(*prefix_keys.find_by_order(i) + keys[i]);
    
    


    int ans = 0;

    for(int i = 0; i <= closed_chests.size(); i++){
        int operations = i;
        int gold = *prefix_closed_chests.find_by_order(i);

        
        if(*prefix_keys.find_by_order(keys.size()) < i)
            continue;
        
        operations += prefix_keys.order_of_key(i);
        //cout << operations << " " << i << " " << prefix_keys.order_of_key(i) << endl;
        
        if(operations > m)
            continue;

        gold += *prefix_opened_chests.find_by_order(min((ll)opened_chests.size(), m - operations));
        
        ans = max(ans, gold);
    }

    cout << ans << endl;
    return 0;
}