#include <cpplib/stdinc.hpp>

int n, x, y, yp, z, smc;

void dfs1(vvi &adj, vi &cnt, int u, int p){
    cnt[u] = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs1(adj, cnt, v, u);
        cnt[u] += cnt[v];
    }
}

void dfs2(vvi &adj, vi &cnt, int u, int p, int acc){
    int cur = acc;
    for(int v:adj[u]){
        if(v == p)
            continue;
        cur = max(cur, cnt[v]);
    }
    if(cur < smc){
        x = u;
        y = -1;
        smc = cur;
    }
    else if(cur == smc){
        y = u;
        yp = p;
    }
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs2(adj, cnt, v, u, acc+cnt[u]-cnt[v]);
    }
}

void dfs3(vvi &adj, int u, int p){
    if(adj[u].size() == 1){
        y = adj[u][0];
        z = u;
        return;
    }
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs3(adj, v, u);
        return;
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        vvi adj(n);
        for(int i=1; i<n; ++i){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].eb(b);
            adj[b].eb(a);
        }

        vi cnt(n);
        dfs1(adj, cnt, 0, -1);
        x = -1;
        y = -1;
        z = -1;
        smc = n;
        dfs2(adj, cnt, 0, -1, 0);
        if(y == -1){
            cout << x+1 << ' ' << adj[x][0]+1 << endl;
            cout << x+1 << ' ' << adj[x][0]+1 << endl;
        }
        else{
            dfs3(adj, y, yp);
            cout << y+1 << ' ' << z+1 << endl;
            cout << x+1 << ' ' << z+1 << endl;
        }
    }
    return 0;
}
