#include <bits/stdc++.h>
using namespace std;

const int MAX = 2*1e5 + 19;
typedef long long ll;
#define int long long
int a[MAX], b[MAX];
int d[MAX], f[MAX];


signed main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n + m + 1; i++)
            cin >> a[i];
        for(int i = 0; i < n + m + 1; i++)
            cin >> b[i];


        int res1 = 0;
        int cnt_n = 0, cnt_m = 0;
        for(int i = 0; i < n + m + 1; i++)
        {
            if(((a[i] > b[i]) && cnt_n < n + 1) || (cnt_m == m)) {
                res1 += a[i];
                d[i] = 1;
                cnt_n++;
            }
            else {
                res1 += b[i];
                d[i] = 2;
                cnt_m++;
            }
        }

        int res2 = 0;
        cnt_n = 0, cnt_m = 0;
        for(int i = 0; i < n + m + 1; i++)
        {
            if(((a[i] > b[i]) && cnt_n < n) || (cnt_m == m + 1)){
                res2 += a[i];
                f[i] = 1;
                cnt_n++;
            }
            else{
                res2 += b[i];
                f[i] = 2;
                cnt_m++;
            }
        }
  
        for(int i = 0; i < n + m + 1; i++)
        {
            if(d[i] == 1)
                cout<<res1 - a[i] << " ";
            else 
                cout<< res2 - b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}