#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/union-find.hpp>

ii dfs(vvi &adj, vb &vis, int u, int p = -1, bool ok = false){
    vis[u] = true;

    ii res(-1, -1);
    for(int v:adj[u]){
        if(v == p)
            continue;
        else if(vis[v]){
            if(!ok){
                res = {u, v};
                ok = true;
            }
            continue;
        }
        ii aux = dfs(adj, vis, v, u, ok);
        if(aux != ii(-1, -1)){
            res = aux;
            ok = true;
        }
    }
    if(ok)
        return res;

    for(int v:adj[u]){
        if(v == p)
            continue;
        return {u, v};
    }
    return {-1, -1};
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int m, n = 0;
        cin >> m;
        vvi adj;
        map<int, int> comp, dcomp;
        map<ii, int> etoi;
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            etoi[ii(a, b)] = i+1;

            if(!comp.count(a)){
                dcomp[n] = a;
                comp[a] = n++;
                adj.eb(vi());
            }
            a = comp[a];
            if(!comp.count(b)){
                dcomp[n] = b;
                comp[b] = n++;
                adj.eb(vi());
            }
            b = comp[b];

            adj[a].eb(b);
            adj[b].eb(a);
        }
        int k = 0;
        ii res;
        vb vis(n);
        vector<tuple<int, int, int> > ans;
        for(int i=0; i<n; ++i){
            if(vis[i])
                continue;
            if(++k > 1){
                int a = dcomp[res.ff], b = dcomp[res.ss], w;
                if(etoi.count(ii(a, b)))
                    w = etoi[ii(a, b)];
                else
                    w = etoi[ii(b, a)];
                ans.eb(w, b, dcomp[i]);
            }
            res = dfs(adj, vis, i);
        }

        cout << ans.size() << endl;
        for(auto t:ans){
            int w, a, b;
            tie(w, a, b) = t;
            cout << w << ' ' << a << ' ' << b << endl;
        }
    }
    return 0;
}
