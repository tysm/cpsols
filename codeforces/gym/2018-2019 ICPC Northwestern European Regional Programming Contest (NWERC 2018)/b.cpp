#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n+1), cnt(n+1);
    vvi adj(n+1);

    for(int i=1; i<=n; ++i){
        cin >> arr[i];

        int m;
        cin >> m;
        for(int j=0; j<m; ++j){
            int x;
            cin >> x;
            adj[i].eb(x);
            cnt[x]++;
        }
    }

    min_heap<ii> pq;
    for(int i=1; i<=n; ++i){
        if(!cnt[i])
            pq.emplace(arr[i], i);
    }

    int cur = n-1, ans = -1;
    while(!pq.empty()){
        ii u = pq.top();
        pq.pop();
        ans = max(ans, u.ff+cur);
        cur--;
        for(int v:adj[u.ss]){
            cnt[v]--;
            if(!cnt[v])
                pq.emplace(arr[v], v);
        }
    }
    cout << ans << endl;
    return 0;
}
