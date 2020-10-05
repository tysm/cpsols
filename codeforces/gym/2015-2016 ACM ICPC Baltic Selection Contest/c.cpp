#include <cpplib/stdinc.hpp>

int dfs1(vvi &adj, vi &val, int u, int acc){
    if(adj[u].empty())
        return val[u];
    bool adjp1 = adj[u].size() > 1;

    int res = (acc? -LINF : LINF);
    for(int v:adj[u]){
        if(acc)
            res = max(res, dfs1(adj, val, v, acc - adjp1));
        else
            res = min(res, dfs1(adj, val, v, 0));
    }
    return res;
}

int dfs2(vvi &adj, vi &val, int u, int acc){
    if(adj[u].empty())
        return val[u];
    bool adjp1 = adj[u].size() > 1;

    int res = (acc? LINF : -LINF);
    for(int v:adj[u]){
        if(acc)
            res = min(res, dfs2(adj, val, v, acc-adjp1));
        else
            res = max(res, dfs2(adj, val, v, 0));
    }
    return res;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int pi;
        cin >> pi;
        adj[pi-1].eb(i);
    }

    int l = 0;
    for(int i=0; i<n; ++i){
        if(adj[i].empty())
            l++;
    }

    vi val(n);
    for(int i=0; i<n; ++i)
        cin >> val[i];

    int m = n-l-k;

    int maval = dfs1(adj, val, 0, m);
    int mival = dfs2(adj, val, 0, k);
    cout << mival << ' ' << maval << endl;
    return 0;
}
