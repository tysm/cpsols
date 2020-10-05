#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi nadj(n);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nadj[u].eb(v);
        nadj[v].eb(u);
    }

    DSU dsu(n);
    map<int, int> cnt;
    for(int v=0; v<n; ++v){
        for(int u:nadj[v])
            cnt[dsu.find(u)]++;
        vi rem;
        for(auto &[u, c] : cnt){
            if(c < dsu.size(u)){
                dsu.merge(u, v);
                rem.eb(u);
            }
            c = 0;
        }
        for(int u:rem)
            cnt.erase(u);
        cnt[dsu.find(v)] = 0;
    }

    set<int> res;
    for(int i=0; i<n; ++i)
        res.ep(dsu.find(i));
    vi ans;
    for(int i:res)
        ans.eb(dsu.size(i));
    sort(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
