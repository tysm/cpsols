#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

void dfs(vvi &adj, vvi &up, int p, int u){
    up[u][0] = p;
    for(int i=1, j=0; i<up[u].size(); ++i, ++j){
        up[u][i] = up[up[u][j]][j];
    }
    for(int v:adj[u])
        dfs(adj, up, u, v);
}

int find_up(vvi &up, int u, int k){
    while(u and k){
        int p = min((int)log2(k), (int)up[u].size()-1);
        u = up[u][p];
        k -= bexp(2, p);
    }
    return k? -1 : (u? u : -1);
}

int32_t main(){
    // https://cses.fi/problemset/task/1687
    desync();
    int n, q;
    cin >> n >> q;
    vvi adj(n+1);
    for(int i=2; i<=n; ++i){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    vvi up(n+1, vi(ceil(log2(n))));
    dfs(adj, up, 0, 1);
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << find_up(up, x, k) << endl;
    }
    return 0;
}
