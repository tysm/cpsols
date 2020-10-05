#include <cpplib/stdinc.hpp>
#include <cpplib/graph/kruskal.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vtt e;
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        e.eb(w, u-1, v-1);
    }

    e = kruskal(n, e);
    int ans = 0;
    for(auto [w, u, v] : e)
        ans = max(ans, w);
    cout << ans << endl;
    return 0;
}
