#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/union-find.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1676
    desync();
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n+1);
    ii ans = {n, 1};
    while(m--){
        int a, b;
        cin >> a >> b;
        if(dsu.merge(a, b))
            ans.ff--;
        ans.ss = max((size_t)ans.ss, dsu.size(a));
        cout << ans.ff << ' ' << ans.ss << endl;
    }
    return 0;
}
