#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi arr(n+1), pos(n+1);
    iota(all(arr), 0);
    iota(all(pos), 0);

    vii ans(n+1);
    for(int i=1; i<=n; ++i)
        ans[i] = {i, i};

    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        int p = pos[x];
        if(p == 1)
            continue;
        int l = arr[p-1];
        swap(arr[p-1], arr[p]);
        swap(pos[l], pos[x]);
        ans[x].ff = min(ans[x].ff, p-1);
        ans[l].ss = max(ans[l].ss, p);
    }

    for(int i=1; i<=n; ++i)
        cout << ans[i].ff << ' ' << ans[i].ss << endl;
    return 0;
}
