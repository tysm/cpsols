#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vvii adj(n);

    int m = n*(n-1)/2;
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].eb(w, v);
        adj[v].eb(w, u);
    }
    return 0;
}
