#include <cpplib/stdinc.hpp>

bool bfs(vvii &adj, int k, int d){
    int n = adj.size();
    vi dis(n, LINF);

    queue<int> q;

    q.ep(0);
    dis[0] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v, w] : adj[u]){
            if(w > k or dis[v] != LINF)
                continue;
            dis[v] = dis[u]+1;
            q.ep(v);
        }
    }
    return dis[n-1] <= d;
}

int32_t main(){
    desync();
    int n, m, d;
    cin >> n >> m >> d;

    vvii adj(n);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].eb(v-1, w);
    }

    int lo = 1, hi = 1e9, ans = LINF;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(bfs(adj, mid, d)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }

    if(ans == LINF)
        cout << -1 << endl;
    else{
        vi p(n, LINF);
        queue<int> q;
        q.ep(0);
        p[0] = -1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto [v, w] : adj[u]){
                if(w > ans or p[v] != LINF)
                    continue;
                p[v] = u;
                q.ep(v);
            }
        }
        vi res;
        int cur = n;
        while(p[cur-1] != -1){
            res.eb(cur);
            cur = p[cur-1]+1;
        }
        res.eb(1);
        reverse(all(res));
        cout << res.size()-1 << endl;
        cout << res << endl;
    }
    return 0;
}
