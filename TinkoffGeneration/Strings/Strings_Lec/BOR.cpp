struct Node{
    int cnt;
    int go[26];

    Node(){
        cnt = 0;
        memset(go, -1, sizeof(go));
    }
};


vector<Node> trie;


void init(){
    trie.emplace_back();
}

void add_string(const string& s){
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        if(trie[v].go[s[i] - 'a'] == -1){
            trie.emplace_back();
            trie[v].go[s[i] - 'a'] = trie.size() - 1;
        }
        v = trie[v].go[s[i] - 'a'];
    }
    ++trie[v].cnt;
}


bool exists(const string& s){
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        if(trie[v].go[s[i] - 'a'] == -1){
            return false;
        }
        v = trie[v].go[s[i] - 'a'];
    }
    return trie[v].cnt > 0;
}