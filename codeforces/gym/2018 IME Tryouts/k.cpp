#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

vvi dijkstra(int s, vvii &adj){
    vvi dis(adj.size(), vi(3, LINF));
    dis[s][0] = 0;
    min_heap<pair<int, ii> > q;
    q.emplace(0, ii(s, 0));
    while(!q.empty()){
        int d = q.top().ff, u = q.top().ss.ff, r = q.top().ss.ss;
        q.pop();
        if(d > dis[u][r])
            continue;
        r = (r+1)%3;
        for(ii i:adj[u]){
            int v = i.ff, w = i.ss;
            if(d+w < dis[v][r]){
                dis[v][r] = d+w;
                q.emplace(dis[v][r], ii(v, r));
            }
        }
    }
    return dis;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vvii adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a != n)
            adj[a].eb(b, c);
        if(b != n)
            adj[b].eb(a, c);
    }
    vvi dis = dijkstra(1, adj);
    set<pair<int, string> > ans;
    ans.insert({dis[n][0], "me"});
    ans.insert({dis[n][1], "Gon"});
    ans.insert({dis[n][2], "Killua"});
    for(pair<int, string> p:ans)
        cout << p.ss << endl;
    return 0;
}
