#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

using tt3 = tuple<int, int, int>;

int sum[2];
vector<vector<tt3> > adj(1e5+1);

max_heap<tt3> pq[2];

int dfs(int u, int par = -1){
    int res = 0;
    for(auto p:adj[u]){
        int v, w, k;
        tie(v, w, k) = p;
        if(v == par)
            continue;
        int cnt =  dfs(v, u);
        pq[k].emplace(cnt*(w - w/2), cnt, w);

        sum[k] += cnt*w;
        res += cnt;
    }
    return res == 0? 1 : res;
}

vi solve(int k){
    vi ans(1, sum[k]);
    while(sum[k] > 0){
        int c, cnt, w;
        tie(c, cnt, w) = pq[k].top();
        pq[k].pop();

        sum[k] -= c;
        ans.eb(sum[k]);

        w /= 2;
        pq[k].emplace(cnt*(w - w/2), cnt, w);
    }
    ans.eb(0);
    return ans;
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
            int a, b, c, k;
            cin >> a >> b >> c >> k;
            a--;
            b--;
            k--;
            adj[a].eb(b, c, k);
            adj[b].eb(a, c, k);
        }

        sum[0] = sum[1] = 0;
        for(int i=0; i<2; ++i)
            pq[i] = max_heap<tt3>();
        dfs(0);

        vi v[2] = {solve(0), solve(1)};

        int ans = LINF;
        for(int i=0, p = v[1].size()-1; i<v[0].size() and p>=0; ++i){
            while(p > 0 and v[0][i] + v[1][p-1] <= s)
                p--;
            if(v[0][i] + v[1][p] <= s)
                ans = min(ans, i + 2*p);
        }
        cout << ans << endl;
    }
    return 0;
}
