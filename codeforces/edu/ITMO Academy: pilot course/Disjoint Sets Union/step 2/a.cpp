#include <cpplib/stdinc.hpp>

int n;
vi link;

int repr(int u){
    if(u == link[u])
        return u;
    if(link[u] == INF)
        return INF;
    return link[u] = repr(link[u]);
}

void pop(int u){
    if(u == n)
        link[u] = INF;
    else
        link[u] = repr(u+1);
}

int32_t main(){
    desync();
    int m;
    cin >> n >> m;

    link.resize(n+1);
    iota(all(link), 0);

    for(int i=0; i<m; ++i){
        char op;
        cin >> op;

        int pos;
        cin >> pos;

        if(op == '?')
            cout << (repr(pos) == INF? -1 : repr(pos)) << endl;
        else
            pop(pos);
    }
    return 0;
}
