#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi p(n+1, -1);
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].eb(v);
        p[v] = u;
    }

    for(int i=1; i<=n; ++i){
        if(p[i] == -1){
            adj[0].eb(i);
            p[i] = 0;
        }
    }

    vi depth(n+1, -1);
    queue<int> q;
    q.ep(0);
    depth[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            depth[v] = depth[u]+1;
            q.ep(v);
        }
    }
    debug(depth);

    bool ok = true;
    set<ii> ans;
    for(int u=1; u<=n; ++u){
        int v;
        cin >> v;

        int res = 0;
        for(int i:hld.query(v, u))
            res += i;
        debug(res);
        debug(hld.query(v, u));

        if(res){
            ok = false;
            break;
        }
        else{
            ans.ep(-depth[v], v);
            hld.update(v, u, 1);
        }
    }
    if(!ok)
        cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(ii i:ans)
            cout << i.ss << endl;
    }
    return 0;
}
