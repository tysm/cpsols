#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

vi dijlike(vvii &adj, int s){
    vi ans(adj.size(), -1);
    ans[s] = LINF;

    max_heap<ii> pq;
    pq.emplace(LINF, s);

    while(!pq.empty()){
        int w = pq.top().ff, u = pq.top().ss;
        pq.pop();
        for(ii p:adj[u]){
            int v = p.ff, c = min(w, p.ss);
            if(c > ans[v]){
                ans[v] = c;
                pq.emplace(c, v);
            }
        }
    }
    return ans;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    vvii adj(n);
    for(int i=1; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].eb(b, c);
        adj[b].eb(a, c);
    }
    vi ans = dijlike(adj, n-1);
    for(int i=0; i<n-1; ++i){
        if(i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
