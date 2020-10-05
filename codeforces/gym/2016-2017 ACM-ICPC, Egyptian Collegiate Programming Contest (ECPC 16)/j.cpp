#include <cpplib/stdinc.hpp>
#include <cpplib/graph/lca.hpp>

int n;
vi arr(5e5+1), cnt(5e5+1), ans(5e5+1);
vvi adj(5e5+1);
vvii adjc(5e5+1);

int dfs(LCA &lca, vi &aux, int u, int par = -1, int dist = 0){
    int a = aux.size() - (lower_bound(all(aux), dist - arr[u]) - aux.begin());
    if(a)
        cnt[lca.ancestor(u, a)]++;
    aux.eb(dist);
    int res = 0;
    for(ii &p:adjc[u]){
        int v = p.ff, w = p.ss;
        if(v == par)
            continue;
        res += dfs(lca, aux, v, u, dist + w);
    }
    ans[u] = res;
    aux.pop_back();
    return res + (a > 0) - cnt[u];
}

int32_t main(){
    ifstream cin("car.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> arr[i];
            cnt[i] = 0;
            adj[i].clear();
            adjc[i].clear();
        }

        for(int i=1; i<n; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            adj[a].eb(b);
            adj[b].eb(a);
            adjc[a].eb(b, c);
            adjc[b].eb(a, c);
        }

        LCA lca(n, adj, 0);

        vi aux;
        dfs(lca, aux, 0);

        for(int i=0; i<n; ++i)
            cout << ans[i] << " \n"[i == n-1];
    }
    return 0;
}
