#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    int s, t;
    cin >> s >> t;

    set<int> aux;

    vvtt adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        adj[u].eb(v, l, r);

        aux.ep(l-1);
        aux.ep(l);
        aux.ep(l+1);
        aux.ep(r-1);
        aux.ep(r);
        aux.ep(r+1);
    }

    vi vals(all(aux));
    vii res;
    for(int i:vals){
        int ok = false;

        queue<int> q;
        vb vis(n+1);

        q.ep(s);
        vis[s] = true;

        while(!q.empty() and !ok){
            int u = q.front();
            q.pop();

            if(u == t)
                ok = true;

            for(auto [v, l, r] : adj[u]){
                if(vis[v] or i < l or i > r)
                    continue;
                q.ep(v);
                vis[v] = true;
            }
        }
        res.eb(i, ok);
    }

    int ans = 0;
    for(int i=0; i<res.size(); ++i){
        if(!res[i].ss)
            continue;
        int j=i;
        while(j < res.size()-1 and res[j+1].ss)
            j++;
        ans += res[j].ff - res[i].ff+1;
        i = j;
    }
    cout << ans << endl;
    return 0;
}
