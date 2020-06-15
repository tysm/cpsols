#include <cpplib/stdinc.hpp>

ii dfs(vvi &adj, vi &p, vi &d, vi &x, vi &y, int u, int acc = 0){
    d[u] = acc;
    if(d[u]%2)
        y.pb(u);
    else
        x.pb(u);

    ii res;
    for(int v:adj[u]){
        if(v == p[u])
            continue;
        if(d[v] == -1){
            p[v] = u;
            ii aux = dfs(adj, p, d, x, y, v, acc+1);
            if(!res.ff or d[aux.ss] - d[aux.ff] < d[res.ss] - d[res.ff])
                res = aux;
        }
        else if(d[v] < d[u]){
            if(!res.ff or d[u] - d[v] < d[res.ss] - d[res.ff])
                res = {v, u};
        }
    }
    return res;
}

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi p(n+1), d(n+1, -1), ans11, ans12;
    ii res = dfs(adj, p, d, ans11, ans12, 1);
    if(res.ff){
        vi ans;
        for(int u=res.ss; u!=res.ff; u=p[u])
            ans.pb(u);
        ans.pb(res.ff);
        reverse(all(ans));
        if(ans.size() <= k){
            cout << 2 << endl;
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); ++i){
                if(i)
                    cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
        else{
            cout << 1 << endl;
            for(int i=0; i<k; ++i){
                if(i%2)
                    continue;
                if(i)
                    cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
    }
    else{
        k = k/2 + k%2;
        cout << 1 << endl;
        if(ans11.size() >= k){
            for(int i=0; i<k; ++i){
                if(i)
                    cout << ' ';
                cout << ans11[i];
            }
            cout << endl;
        }
        else{
            for(int i=0; i<k; ++i){
                if(i)
                    cout << ' ';
                cout << ans12[i];
            }
            cout << endl;
        }
    }
    return 0;
}
