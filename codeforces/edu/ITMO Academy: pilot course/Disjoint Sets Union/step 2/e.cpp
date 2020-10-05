#include <cpplib/stdinc.hpp>
#include <cpplib/graph/kruskal.hpp>

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

    edgs = kruskal(n, edgs);
    int ans = 0;
    for(auto [w, u, v] : edgs)
        ans += w;
    cout << ans << endl;
    return 0;
}
