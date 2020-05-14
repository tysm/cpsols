#include <cpplib/stdinc.hpp>

ii dfs(vvi &adj, const ii &e){
    vii vres;
    int sum = 0;
    for(int v:adj[e.ss]){
        if(v == e.ff)
            continue;
        ii res = dfs(adj, {e.ss, v});
        sum += res.ff;
        vres.pb(res);
    }
    ii ans = {sum, 1+sum};
    for(ii &res:vres)
        ans.ff = max(ans.ff, res.ss + sum-res.ff);
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1130
    desync();
    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int leaf = 0;
    for(int i=1; i<=n and !leaf; ++i){
        if(adj[i].size() == 1)
            leaf = i;
    }

    ii ans = dfs(adj, {leaf, adj[leaf][0]});
    cout << max(ans.ff, ans.ss) << endl;
    return 0;
}
