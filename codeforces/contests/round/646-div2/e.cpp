#include <cpplib/stdinc.hpp>

pair<int, ii> dfs(vvi &adj, vector<pair<int, ii> > &prop, int u, int p = -1, int m = INT_MAX){
    int ans = 0;
    ii res = prop[u].ss;
    m = min(m, prop[u].ff);
    for(int v:adj[u]){
        if(v == p)
            continue;
        pair<int, ii> aux = dfs(adj, prop, v, u, m);
        ans += aux.ff;
        res.ff += aux.ss.ff;
        res.ss += aux.ss.ss;
    }
    int aux = min(res.ff, res.ss);
    ans += m*aux*2;
    return {ans, {res.ff-aux, res.ss-aux}};
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    vector<pair<int, ii> > prop(n+1);
    for(int i=1; i<=n; ++i){
        int c, a, b;
        cin >> c >> a >> b;
        prop[i] = {c, {0, 0}};
        if(a != b){
            if(b)
                prop[i].ss.ss = 1;
            else
                prop[i].ss.ff = 1;
        }
    }
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    pair<int, ii> ans = dfs(adj, prop, 1);
    if(ans.ss.ff or ans.ss.ss)
        cout << -1 << endl;
    else
        cout << ans.ff << endl;
    return 0;
}
