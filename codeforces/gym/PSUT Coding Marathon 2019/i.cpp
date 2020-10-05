#include <cpplib/stdinc.hpp>
#include <cpplib/graph/tree/lowest-common-ancestor.hpp>

vi prj, ans, last;
vvi adj(1);
LCA lca(adj, 0);

void dfs(int acc, int u, int p = -1){
    int pu = prj[u];
    if(!last[pu])
        ans[pu] += acc;
    else
        ans[pu] += lca.distance(u, lca.query(last[pu], u));
    last[pu] = u;
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs(acc+1, v, u);
    }
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    prj.resize(n+1);
    for(int i=1; i<=n; ++i)
        cin >> prj[i];
    adj.resize(n+1);
    int root;
    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;
        if(x == 0){
            root = i;
            continue;
        }
        adj[x].eb(i);
    }
    lca = LCA(adj, root);
    last.resize(m+1);
    ans.resize(m+1);
    dfs(1, root);
    for(int i=1; i<=m; ++i){
        if(i > 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
