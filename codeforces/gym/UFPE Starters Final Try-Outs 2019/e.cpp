#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/modular-multiplicative-inverse.hpp>

void subcompute(vvi &adj, vi &sum, vi &cnt, int u, int p = -1){
    cnt[u] = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;
        subcompute(adj, sum, cnt, v, u);
        sum[u] = (sum[u] + sum[v] + cnt[v])%M;
        cnt[u] += cnt[v];
    }
}

void compute(int n, vvi &adj, vi &sum, vi &cnt, int u, int p = -1){
    if(p != -1)
        sum[u] = (sum[p] - cnt[u] + n - cnt[u])%M;
    for(int v:adj[u]){
        if(v == p)
            continue;
        compute(n, adj, sum, cnt, v, u);
    }
}

int32_t main(){
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

    vi sum(n+1), cnt(n+1);
    subcompute(adj, sum, cnt, 1);
    compute(n, adj, sum, cnt, 1);

    int ans = 0;
    for(int i=1; i<=n; ++i)
        ans = (ans + sum[i])%M;
    cout << (ans*mmi(n*(n+1)))%M << endl;
    return 0;
}
