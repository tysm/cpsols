#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>
#include <cpplib/adt/segtree.hpp>

void solve(int n, int i, SegTree<RSumQ, int> &res, int k, SegTree<RMaxQ, int> &cur){
    res.update(i, 1);
    cur.update(k, -INF);
    if(k){
        cur.update(0, k-1, 1);

        for(int j = cur.find(0); j<k; j = cur.find(0))
            solve(n, n-1-j, res, j, cur);
    }
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    vi arr(n);
    for(int i=0; i<n; ++i)
        cin >> arr[i];

    vvii qr(n);
    for(int i=0; i<q; ++i){
        int x, y;
        cin >> x >> y;
        qr[x].eb(y, i);
    }
    vi ans(q);

    min_heap<ii> pq;
    SegTree<RSumQ, int> res(n);
    SegTree<RMaxQ, int> cur(vi(n, 0));

    for(int i=n-1, k=0; i>=0; --i, ++k){
        if(arr[i] == i+1)
            solve(n, i, res, k, cur);
        else{
            if(arr[i] < i+1)
                cur.update(k, arr[i]-(i+1));
            else
                cur.update(k, -INF);
        }

        int acc = res.query(i, n-1);
        for(auto [y, j] : qr[i]){
            ans[j] = acc;
            if(y)
                ans[j] -= res.query(n-y, n-1);
        }
    }
    for(int i:ans)
        cout << i << endl;
    return 0;
}
