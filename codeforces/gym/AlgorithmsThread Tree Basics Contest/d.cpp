#include <cpplib/stdinc.hpp>

vi height;
vvi up, res;
vvii adj;

void dfs(int u, int p){
    for(int i=1, j=0; i<up[u].size() and up[u][j] != -1; ++i, ++j){
        up[u][i] = up[up[u][j]][j];
        res[u][i] = res[up[u][j]][j];
        res[u][i] = min(res[u][i], res[u][j]);
    }
    for(auto [v, w] :adj[u]){
        if(v == p)
            continue;
        up[v][0] = u;
        res[v][0] = w;

        height[v] = height[u] + 1;
        dfs(v, u);
    }
}

int query(int u, int v){
    int ans = LINF;
    if(height[u] > height[v])
        swap(u, v);
    while(height[v] > height[u]){
        int d = height[v] - height[u];
        ans = min(ans, res[v][(int)log2(d)]);
        v = up[v][(int)log2(d)];
    }
    if(u == v)
        return ans;
    for(int i=up[u].size() - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            ans = min(ans, res[u][i]);
            ans = min(ans, res[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    return min({ans, res[u][0], res[v][0]});
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }

    height.resize(n);
    up.resize(n, vi(2+log2(n), -1));
    res.resize(n, vi(2+log2(n), -1));
    dfs(0, -1);

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << query(u, v) << endl;
    }
    return 0;
}
