const int k = 26;

struct Vertex {
    Vertex* to[k] = {0}; // нулевой указатель означает, что перехода нет
    bool terminal = 0;
};

Vertex *root = new Vertex();
void add_string(string &s) {
    v = root;
    for (char c : s) {
        c -= 'a'; // получаем число от 0 до 25
        if (!v->to[c]) 
            v->to[c] = new Vertex();
        v = v->to[c];
    }
    v->terminal = true;
}
bool find(string &s) {
    v = root;
    for (char c : s) {
        c -= 'a';
        if (!v->to[c])
            return false;
        v = v->to[c];
    }
    return v->terminal;
}

bool erase(string &s) {
    v = root;
    for (char c : s)
        v = v->to[c - 'a'];
    v->terminal = false;
}



