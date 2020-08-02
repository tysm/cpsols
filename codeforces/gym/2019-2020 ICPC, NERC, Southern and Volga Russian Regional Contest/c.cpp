#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vector<vector<pair<ii, int> > > arr(2e5+1);
    for(int i=1; i<=n; ++i){
        int l, r, p;
        cin >> l >> r >> p;
        arr[r].eb(ii(l, p), i);
    }
    SegTree<RMaxQ, int> st(vi(2e5+1));
    int ans = 0;
    ii bounds;
    for(int r=1; r<2e5+1; ++r){
        st.update(1, r, -k);
        for(pair<ii, int> aux:arr[r]){
            ii i = aux.ff;
            st.update(1, i.ff, i.ss);
            int v = st.query(1, r);
            if(v > ans){
                bounds = {st.find(v), r};
                ans = v;
            }
        }
    }
    if(!ans)
        cout << 0 << endl;
    else{
        cout << ans << ' ' << bounds.ff << ' ' << bounds.ss << ' ';
        vi res;
        for(int r=1; r<=bounds.ss; ++r){
            for(pair<ii, int> i:arr[r]){
                if(i.ff.ff >= bounds.ff)
                    res.eb(i.ss);
            }
        }
        cout << res.size() << endl;
        for(int i=0; i<res.size(); ++i){
            if(i)
                cout << ' ';
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}
