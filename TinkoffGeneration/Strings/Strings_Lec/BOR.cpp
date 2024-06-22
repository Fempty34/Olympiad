const int k = 26;

struct Vertex
{
    Vertex* to[k] = {0};
    bool isTerminal = false;
};

Vertex *root = new Vertex();

void addString(string &s){
    v = root;
    for(char c : s){
        c -= 'a';
        if(!v->to[c])
            v->to[c] = new Vertex();
        v = v->to[c];
    }
    v->isTerminal = true;
}

bool findString(string &s){
    v = root;
    for(char c : s){
        c -= 'a';
        if(!v->to[c])
            return false;
        v = v->to[c];
    }
    return v->isTerminal;
}

void eraseString(string &s){
    v = root;
    for(char c : s){
        v = v->to[c];
    }
    v->isTerminal = false;

}





