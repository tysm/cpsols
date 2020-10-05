#include <cpplib/stdinc.hpp>
#include <cpplib/graph/treedmtr.hpp>

void bfs(int s, vvi &adj, vi &dis){
    queue<int> q;
    q.ep(s);
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(dis[v] != -1)
                continue;
            dis[v] = dis[u]+1;
            q.ep(v);
        }
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1].eb(v-1);
        adj[v-1].eb(u-1);
    }

    int s1, s2, ans;
    tie(s1, s2, ans) = tree_diameter(adj);

    vi dis1(n, -1), dis2(n, -1);
    bfs(s1, adj, dis1);
    bfs(s2, adj, dis2);

    for(int i=0; i<n; ++i)
        cout << max(ans, max(dis1[i], dis2[i])+1) << endl;
    return 0;
}
