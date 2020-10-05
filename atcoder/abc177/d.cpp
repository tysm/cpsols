#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.merge(u, v);
    }

    set<int> ans;
    for(int i=0; i<n; ++i)
        ans.ep(-dsu.size(i));
    cout << -(*ans.begin()) << endl;
    return 0;
}
