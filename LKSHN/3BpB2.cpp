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

int f(string s){
   int n = s.size();
   int count_B = 0, count_W = 0, count_R = 0;
   for (int i = 0; i < n; ++i){
      if (s[i] == 'B') count_B++;
      if (s[i] == 'W') count_W++;
      if (s[i] == 'R') count_R++;
   }
   cout << "B: " << count_B << " W: " << count_W << " R: " << count_R << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<char> a;

    string s1;
    cin >> s1;

    string s2;

    for (int i = 0; i < n - 1; ++i)
    {
       for (int i = 0; i < s1.size() - 1; ++i)
       {
              if (s1[i] == s1[i + 1])
                    s2 += s1[i];
              else{
                     if(s1[i] != 'R' && s1[i+1] != 'R')
                        s2 += 'R';
                     else if(s1[i] != 'W' && s1[i+1] != 'W')
                        s2 += 'W';
                     else
                        s2 += 'B';
              }
       }
       //cout << "-> " << s2 << endl;
       //f(s2);
       s1 = s2;
       s2.clear();
    }
    cout << s1 << endl;


    return 0;
}
