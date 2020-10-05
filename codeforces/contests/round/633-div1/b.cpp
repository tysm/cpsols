#include <cpplib/stdinc.hpp>
#include <cpplib/graph/treedmtr.hpp>

void dfs(vvi &adj, vb &vis, int u, int &lo, int &m, int &l, int acc){
    if(adj[u].size() == 1){
        if(acc%2)
            lo = 3;
        l++;
    }
    bool addm = false;
    vis[u] = true;
    for(int v:adj[u]){
        if(adj[v].size() == 1)
            addm = true;
        if(vis[v])
            continue;
        dfs(adj, vis, v, lo, m, l, acc+1);
    }
    m += addm;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1].eb(v-1);
        adj[v-1].eb(u-1);
    }

    int lo = 1, m = 0, l = 0;
    vb vis(n);
    for(int i=0; i<n; ++i){
        if(adj[i].size() == 1){
            dfs(adj, vis, i, lo, m, l, 0);
            break;
        }
    }
    cout << lo << ' ' << n-1-l+m << endl;
    return 0;
}
