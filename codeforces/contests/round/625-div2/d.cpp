#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1), inv_adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].eb(b);
        inv_adj[b].eb(a);
    }
    int k;
    cin >> k;
    vi p(k);
    for(int &i:p)
        cin >> i;
    vi dis(n+1, INF);
    dis[p.back()] = 0;
    queue<int> q;
    q.push(p.back());
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:inv_adj[u]){
            if(dis[v] != INF)
                continue;
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
    ii ans = {0, 0};
    for(int i=0; i<k-1; ++i){
        int u = p[i], mind = INF, acc = 0;
        for(int v:adj[u]){
            if(dis[v] < mind){
                mind = dis[v];
                acc = 1;
            }
            else if(dis[v] == mind)
                acc++;
        }
        if(dis[p[i+1]] > mind)
            ans.ff++;
        else
            acc--;
        ans.ss += (acc != 0);
    }
    cout << ans.ff << ' ' << ans.ss << endl;
    return 0;
}
