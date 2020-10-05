#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

pair<vtt, DSU> kruskal(int n, vtt &edgs, int k){
    DSU dsu(n);
    vtt res;
    for(auto [w, u, v] : edgs){
        if(w < k)
            continue;
        if(dsu.merge(u, v))
            res.eb(w, u, v);
    }
    return {res, dsu};
}

bool check(int n, DSU &dsu){
    for(int i=1; i<n; ++i){
        if(!dsu.same(i, i-1))
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vtt edgs;
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edgs.eb(w, u-1, v-1);
    }
    sort(all(edgs));

    int ans = INF;
    for(int i=0; i<m; ++i){
        auto [res, dsu] = kruskal(n, edgs, get<0>(edgs[i]));
        if(check(n, dsu)){
            int ma = -INF, mi = INF;
            for(auto [w, u, v] : res){
                ma = max(w, ma);
                mi = min(w, mi);
            }
            ans = min(ans, ma-mi);
        }
        else
            break;
    }
    cout << (ans == INF? "NO" : "YES") << endl;
    if(ans < INF)
        cout << ans << endl;
    return 0;
}
