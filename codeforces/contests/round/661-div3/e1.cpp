#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

using tt3 = tuple<int, int, int>;

int sum;
vvii adj(1e5+1);
max_heap<tt3> pq;

int dfs(int u, int par = -1){
    int res = 0;
    for(auto p:adj[u]){
        int v = p.ff, w = p.ss;
        if(v == par)
            continue;
        int cnt =  dfs(v, u);
        pq.emplace(cnt*(w - w/2), cnt, w);

        sum += cnt*w;
        res += cnt;
    }
    return res == 0? 1 : res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        for(int i=0; i<n; ++i)
            adj[i].clear();
        for(int i=1; i<n; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            adj[a].eb(b, c);
            adj[b].eb(a, c);
        }

        sum = 0;
        pq = max_heap<tt3>();
        dfs(0);

        int ans = 0;
        while(sum > s){
            int c, cnt, w;
            tie(c, cnt, w) = pq.top();
            pq.pop();

            sum -= c;

            w /= 2;
            pq.emplace(cnt*(w - w/2), cnt, w);

            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
