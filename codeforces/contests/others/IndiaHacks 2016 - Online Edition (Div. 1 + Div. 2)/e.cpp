#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();

    int n, m, k;
    cin >> n >> m >> k;

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
    for(int i=1; i<n; ++i){
        for(int j:nadj[i]){
            if(j > i or j == 0)
                continue;
            cnt[dsu.find(j)]++;
        }
        vi rem;
        for(auto &[j, c] : cnt){
            if(c < dsu.size(j)){
                dsu.merge(i, j);
                rem.eb(j);
            }
            c = 0;
        }
        for(int j:rem)
            cnt.erase(j);
        cnt[dsu.find(i)] = 0;
    }

    map<int, vi> res;
    for(int i=1; i<n; ++i)
        res[dsu.find(i)].eb(i);

    int o = 0;
    bool ok = true;
    set<int> nedgs(all(nadj[0]));
    for(auto &[i, v] : res){
        ok = false;
        if(!k)
            break;
        for(int j:v){
            if(nedgs.count(j))
                continue;
            if(!ok){
                k--;
                ok = true;
            }
            else
                o++;
        }
        if(!ok)
            break;
    }
    if(k > o)
        ok = false;

    if(!ok)
        cout << "im";
    cout << "possible" << endl;
    return 0;
}
