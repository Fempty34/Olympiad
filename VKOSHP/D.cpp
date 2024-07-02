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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x0, k;
    cin >> n >> x0 >> k;

    vector<pair<int, int>> left;
    vector<pair<int, int>> right;

    qfor(n) {
        int x, w; cin >> x >> w;
        x -= x0;
        if (x > 0)
            right.pb({x, w});
        else
            left.pb({-x, w});
    }
    sort(all(left));
    sort(all(right));

    //for(auto el : left) {
    //    cout << "(" << el.first << ", " << el.second << ")" << " ";
    //}
    //cout << endl;
//
    //for(auto el : right) {
    //    cout << "(" << el.first << ", " << el.second << ")" << " ";
    //}
    //cout << endl;

    int res = 0;
    int index = 0;
    int s = 0;
    while(index < right.size() && right[index].fr <= k) {
        s += right[index].sc;
        index++;
    }

    res = max(res, s);
    s = 0;
    index = 0;
    while(index < left.size() && left[index].fr <= k) {
        s += left[index].sc;
        index++;
    }
    res = max(res, s);
    //cout << res << endl;
    if(right.size() == 0 || left.size() == 0){
        cout << res << endl;
        return 0;
    }

    vector<int> pref_sum_right;
    vector<int> pref_sum_left;

    pref_sum_right.pb(0);
    pref_sum_left.pb(0);

    for(int i = 0; i < right.size(); i++)
        pref_sum_right.pb(pref_sum_right[i] + right[i].sc);
    for(int i = 0; i < left.size(); i++)
        pref_sum_left.pb(pref_sum_left[i] + left[i].sc);

    //print_array(pref_sum_left);
    //print_array(pref_sum_right);

    int index1 = left.size() - 1;
    int index2 = 0;

    while(index2 < right.size()) {
        if (right[index2].fr > k ) break;
        while(index1 >= 0 && left[index1].fr + 2 * right[index2].fr > k)
            index1--;
        //cout << index1 << " " << index2 << endl;
        if(index1 < 0) index1++;
        if(left[index1].fr + 2 * right[index2].fr > k) break;
        res =  max(res, pref_sum_right[index2 + 1] + pref_sum_left[index1 + 1]);
        index2++;
    }

    //cout << res << endl;
    
    index1 = 0;
    index2 = right.size() - 1;
    while(index1 < left.size()) {
        if (left[index1].fr > k ) break;
        while(index2 >= 0 && 2 * left[index1].fr + right[index2].fr > k)
            index2--;
        
        if(index2 < 0) index2++;
        if(2 * left[index1].fr + right[index2].fr > k) break;
        res =  max(res, pref_sum_right[index2 + 1] + pref_sum_left[index1 + 1]);
        index1++;
    }

    cout << res << endl;
    
    

    return 0;
}
