#include <cpplib/stdinc.hpp>

void dfs(vvi &adj, vi &res, int u){
    res[u] = 0;
    for(int v:adj[u]){
        if(res[v] == -1)
            dfs(adj, res, v);
        res[u] = max(res[u], res[v]);
    }
    res[u]++;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vvi pos(k, vi(n));
    for(int i=0; i<k; ++i){
        for(int j=0; j<n; ++j){
            int x;
            cin >> x;
            pos[i][x-1] = j;
        }
    }

    vvi adj(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j == i)
                continue;
            bool ok = true;
            for(int l=0; l<k; ++l){
                if(pos[l][j] < pos[l][i])
                    ok = false;
            }
            if(ok)
                adj[i].eb(j);
        }
    }
    vi res(n, -1);
    for(int i=0; i<n; ++i){
        if(res[i] == -1)
            dfs(adj, res, i);
    }
    cout << *max_element(all(res)) << endl;
    return 0;
}
