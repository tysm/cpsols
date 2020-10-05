#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    SegTree<RMaxQ, int> st(vi(n, 0));
    int pl = 0, pr = 0, ans = 1;
    for(int i=0; i<n; ++i){
        int l, r;
        cin >> l >> r;
        if(i){
            if(r < pr){
                int v = st.query(r+1, pr);
                st.update(r+1, pr, -v);
            }
            if(l > pl){
                int v = st.query(pl, l-1);
                st.update(pl, l-1, -v);
            }
        }
        st.update(l, r, 1);

        int lo = 1, hi = r-l+1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int idx = st.find(mid);
            if(idx+mid-1 < n and st.query(idx+mid-1) >= mid){
                ans = max(mid, ans);
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        pl = l;
        pr = r;
    }
    cout << ans << endl;
    return 0;
}
