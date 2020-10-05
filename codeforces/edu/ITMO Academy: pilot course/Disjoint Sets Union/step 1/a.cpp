#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for(int i=0; i<m; ++i){
        string s;
        cin >> s;
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(s == "union")
            dsu.merge(u, v);
        else
            cout << (dsu.same(u, v)? "YES" : "NO") << endl;
    }
    return 0;
}
