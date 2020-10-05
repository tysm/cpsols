#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi pts, R(n), Y(n);
    min_heap<ii> op;
    for(int i=0; i<n; ++i){
        int l;
        cin >> l >> Y[i] >> R[i];
        R[i] += l-1;

        pts.eb(l-1);
        pts.eb(l);
        pts.eb(R[i]);
        pts.eb(R[i]+1);

        op.ep(l, i);
    }
    sort(all(pts));

    vi cnt(n);
    min_heap<ii> cur;

    int last = -INF;
    for(int p:pts){
        if(p == last)
            continue;

        while(!op.empty() and op.top().ff == p){
            int i = op.top().ss;
            op.pop();

            cur.ep(Y[i], i);
        }

        while(!cur.empty() and R[cur.top().ss] < p)
            cur.pop();

        if(!cur.empty())
            cnt[cur.top().ss] = true;

        last = p;
    }

    int ans = 0;
    for(int i:cnt)
        ans += (i == 0);
    cout << ans << endl;
    return 0;
}
