#include <cpplib/stdinc.hpp>

void compute_aux(vvi &adj, vi &sum, vi &nodes, int p, int u){
    // debug(p);
    // debug(u);
    nodes[u] = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;
        compute_aux(adj, sum, nodes, u, v);
        sum[u] += sum[v] + nodes[v];
        nodes[u] += nodes[v];
    }
    // debug(u);
    // debug(sum[u]);
    // debug(nodes[u]);
}

void compute_ans(vvi &adj, vi &sum, vi &nodes, vi &ans, int p, int u){
    ans[u] = sum[u];
    if(p)
        ans[u] += ans[p] - (sum[u] + nodes[u]) + (ans.size() - 1 - nodes[u]);
    for(int v:adj[u]){
        if(v == p)
            continue;
        compute_ans(adj, sum, nodes, ans, u, v);
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1133
    desync();
    int n;
    cin >> n;

    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi ans(n+1), sum(n+1), nodes(n+1);
    compute_aux(adj, sum, nodes, 0, 1);
    compute_ans(adj, sum, nodes, ans, 0, 1);
    for(int i=1; i<=n; ++i){
        if(i > 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
