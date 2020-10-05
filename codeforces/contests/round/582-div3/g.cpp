#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    min_heap<tt> edgs;
    for(int i=1; i<n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edgs.ep(w, u-1, v-1);
    }

    vi ans(m);
    vii arr(m);
    for(int i=0; i<m; ++i){
        cin >> arr[i].ff;
        arr[i].ss = i;
    }
    sort(all(arr));

    vi C2(n+1);
    if(n >= 2)
        C2[2] = 1;
    for(int i=3; i<=n; ++i)
        C2[i] = i*C2[i-1]/(i-2);

    DSU dsu(n);
    for(int i=0, cur = 0; i<m; ++i){
        int q = arr[i].ff;
        while(!edgs.empty()){
            auto [w, u, v] = edgs.top();
            if(q < w)
                break;
            edgs.pop();
            int cnt1 = dsu.size(u);
            cur -= C2[cnt1];
            int cnt2 = dsu.size(v);
            cur -= C2[cnt2];
            dsu.merge(u, v);
            int cnt3 = dsu.size(u);
            cur += C2[cnt3];
        }
        ans[arr[i].ss] = cur;
    }
    cout << ans << endl;
    return 0;
}
