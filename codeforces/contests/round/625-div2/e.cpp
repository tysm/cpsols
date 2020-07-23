#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    int n, m, p;
    cin >> n >> m >> p;

    vii we(n);
    for(ii &i:we)
        cin >> i.ff >> i.ss;
    sort(all(we));

    vii ar(m);
    for(ii &i:ar)
        cin >> i.ff >> i.ss;
    sort(all(ar));

    vi bs(m), cbs(m);
    for(int i=0; i<m; ++i){
        bs[i] = ar[i].ff;
        cbs[i] = -ar[i].ss;
    }
    SegTree<RMaxQ, int> st(cbs);

    vector<pair<ii, int> > mo(p);
    for(pair<ii, int> &i:mo)
        cin >> i.ff.ff >> i.ff.ss >> i.ss;
    sort(all(mo));

    int ans = -LINF;
    for(int i=0, j=0; i<n; ++i){
        while(j < p and mo[j].ff.ff < we[i].ff){
            int l = upper_bound(all(bs), mo[j].ff.ss) - bs.begin();
            if(l < bs.size())
                st.update(l, m-1, mo[j].ss);
            j++;
        }
        ans = max(ans, st.query(0, m-1) - we[i].ss);
    }
    cout << ans << endl;
    return 0;
}
