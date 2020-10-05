#include <cpplib/stdinc.hpp>
#include <cpplib/graph/tree/spanning-tree/kruskal.hpp>
#include <cpplib/data-structure/union-find.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1675
    desync();
    int n, m;
    cin >> n >> m;
    UnionFind dsu(n+1);
    vector<pair<int, ii> > edges;
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({c, {a, b}});
        dsu.merge(a, b);
    }

    set<int> cnt;
    for(int i=1; i<=n; ++i)
        cnt.insert(dsu.find(i));
    if(cnt.size() > 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<pair<int, ii> > res = kruskal(n+1, edges);
    int ans = 0;
    for(pair<int, ii> &e:res)
        ans += e.ff;
    cout << ans << endl;
    return 0;
}
