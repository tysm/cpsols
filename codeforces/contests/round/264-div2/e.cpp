#include <cpplib/stdinc.hpp>
#include <cpplib/math/gries-misra.hpp>

Sieve sv(2e6+1);
vvi adj;
vvii mof(2e6+1);
vi ans, val;

void dfs(int u, int d, int p){
    int k = -1;
    ans[u] = -1;
    auto factors = sv.factorization(val[u]);
    for(auto [p, cnt] : factors){
        if(mof[p].empty())
            continue;
        if(ans[u] == -1 or mof[p].back().ss > k){
            ans[u] = mof[p].back().ff;
            k = mof[p].back().ss;
        }
    }
    for(auto [p, cnt] : factors)
        mof[p].eb(u, d);
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs(v, d+1, u);
    }
    for(auto [p, cnt] : factors)
        mof[p].pop_back();
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    val.resize(n+1);
    for(int i=1; i<=n; ++i)
        cin >> val[i];

    adj.resize(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    ans.resize(n+1);
    dfs(1, 0, 0);

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int v;
            cin >> v;
            cout << ans[v] << endl;
        }
        else{
            int v, w;
            cin >> v >> w;
            val[v] = w;
            dfs(1, 0, 0);
        }
    }
    return 0;
}
