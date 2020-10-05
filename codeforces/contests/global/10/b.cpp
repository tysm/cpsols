#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        SegTree<RMaxQ, int> st(arr);
        int mval = st.query(0, n-1);
        st.update(0, n-1, -mval);
        for(int i=0; i<n; ++i)
            arr[i] = st.query(i);
    }
    return 0;
}
