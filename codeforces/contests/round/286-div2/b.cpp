#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vector<vvi> adj(m, vvi(n));
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        w--;
        adj[w][u].eb(v);
        adj[w][v].eb(u);
    }

    int q;
    cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        int ans = 0;
        for(int w=0; w<m; ++w){
            vb vis(n);
            queue<int> q;
            q.ep(i);
            vis[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v:adj[w][u]){
                    if(vis[v])
                        continue;
                    q.ep(v);
                    vis[v] = true;
                }
            }
            ans += vis[j];
        }
        cout << ans << endl;
    }
    return 0;
}
