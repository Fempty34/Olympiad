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

struct Vertex {
    bool isTerminal = false;
    Vertex* sons[2] = {0};
};

Vertex *root = new Vertex();

void addNumber(vector<int> binNumber) {
    Vertex *v = root;
    for(auto x : binNumber) {
        if(!v->sons[x]) v->sons[x] = new Vertex();
        v = v->sons[x];
    }
    v->isTerminal = true;
}

void removeNumber(vector<int> binNumber) {
    Vertex *v = root;
    for(auto x : binNumber) {
        v = v->sons[x];
    }
    v->isTerminal = false;
}


int searchNumber(vector<int> binNumber) {
    int ans = 0;
    Vertex *v = root;
    int n = binNumber.size();
    for(int i = 0; i < n; i++) {
        if(binNumber[i] == 0 && v->sons[1]) {
            ans += pow(2, 31 - i);
            v = v->sons[1];
        }
        else if(binNumber[i] == 0 && !v->sons[1]) {
            v = v->sons[0];
        }
        else if(binNumber[i] == 1 && v->sons[0]) {
            v = v->sons[0];
        }   
        else{
            ans += pow(2, 31 - i);
            v = v->sons[1];
        }
    }
    return ans;
}

vector<int> decToBin(int number) {
    vector<int> binNumber;
    for (int i = 0; i < 32; i++)
    {
        if (number & (1 << i))
            binNumber.push_back(1);
        else
            binNumber.push_back(0);
    }
    reverse(all(binNumber));
    return binNumber;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    addNumber(decToBin(0));
    while(q--){
        char operation;
        int value;
        cin >> operation >> value;
        if(operation == '+'){
            //cout << operation << endl;
            addNumber(decToBin(value));
        }
        else if (operation == '-'){
            //cout << operation << endl;
            removeNumber(decToBin(value));
        }
        else{
            //cout << operation << endl;
            //print_array(decToBin(value));
            cout << searchNumber(decToBin(value)) << endl;
        }
    }
    
    

    return 0;
}
