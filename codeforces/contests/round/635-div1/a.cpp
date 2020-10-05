#include <cpplib/stdinc.hpp>

int dfs(vvi &adj, vi &hap, int u, int p = -1, int d = 0){
    int cnt = 0;
    for(int v:adj[u]){
        if(v == p)
            continue;
        cnt += 1 + dfs(adj, hap, v, u, d+1);
    }
    hap[u] = cnt - d;
    return cnt;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vvi adj(n);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    vi hap(n);
    dfs(adj, hap, 0);
    vii arr(n);
    for(int i=0; i<n; ++i)
        arr[i] = {hap[i], i};
    sort(all(arr));
    int ans = 0;
    for(int i=k; i<n; ++i)
        ans += hap[arr[i].ss];
    cout << ans << endl;
    return 0;
}
