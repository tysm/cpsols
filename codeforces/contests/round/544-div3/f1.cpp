#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    set<ii> vis;
    max_heap<tuple<int, int, int> > pq;
    for(int i=1; i<=n; ++i){
        for(int j:adj[i]){
            if(vis.count(ii(i, j)))
                continue;
            pq.emplace(max(adj[i].size(), adj[j].size()), i, j);
            vis.emplace(i, j);
            vis.emplace(j, i);
        }
    }

    vii ans;
    DSU dsu(n);
    while(!pq.empty()){
        int x, a, b;
        tie(x, a, b) = pq.top();
        pq.pop();
        if(dsu.merge(a-1, b-1))
            ans.eb(a, b);
    }
    for(ii i:ans)
        cout << i.ff << ' ' << i.ss << endl;
    return 0;
}
