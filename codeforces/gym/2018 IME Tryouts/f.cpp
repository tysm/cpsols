#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/union-find.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vii edg(m);
    for(ii &i:edg){
        cin >> i.ff >> i.ss;
        i.ff--;
        i.ss--;
    }

    vi arr(m);
    for(int &i:arr){
        cin >> i;
        i--;
    }
    reverse(all(arr));

    int acc = n;
    vi ans(m);
    UnionFind dsu(n);
    for(int i=0; i<m; ++i){
        ans[i] = acc;
        if(dsu.merge(edg[arr[i]].ff, edg[arr[i]].ss))
            acc--;
    }
    reverse(all(ans));

    for(int i=0; i<m; ++i)
        cout << ans[i] << endl;
    return 0;
}
