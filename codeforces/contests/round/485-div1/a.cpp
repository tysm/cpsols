#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vvi pos(k);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        x--;
        pos[x].eb(i);
    }
    vvi adj(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    vvi dis(n, vi(k, LINF));
    for(int i=0; i<k; ++i){
        queue<int> q;
        for(int j:pos[i]){
            dis[j][i] = 0;
            q.emplace(j);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                if(dis[v][i] != LINF)
                    continue;
                dis[v][i] = dis[u][i]+1;
                q.emplace(v);
            }
        }
    }
    for(int i=0; i<n; ++i){
        int ans = 0;
        sort(all(dis[i]));
        for(int j=0; j<s; ++j)
            ans += dis[i][j];
        cout << ans << endl;
    }
    return 0;
}
