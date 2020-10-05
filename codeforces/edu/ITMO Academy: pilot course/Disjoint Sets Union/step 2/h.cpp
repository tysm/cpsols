#include <cpplib/stdinc.hpp>
#include <cpplib/graph/kruskal.hpp>

int32_t main(){
    desync();
    int n, m, s;
    cin >> n >> m >> s;

    map<tt, int> id;
    vtt edgs;
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edgs.eb(-w, u-1, v-1);
        id[edgs.back()] = i+1;
    }
    sort(rall(edgs));

    auto aux = kruskal(n, edgs);
    set<tt> res(all(aux));

    int acc = 0;
    vi ans;
    for(auto e : edgs){
        if(res.count(e))
            continue;
        int w = -get<0>(e);
        if(acc + w > s)
            break;
        ans.eb(id[e]);
        acc += w;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
