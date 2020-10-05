#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    set<int> xvals, yvals;

    map<int, vii> cir;
    for(int i=0; i<n; ++i){
        int x, y, r;
        cin >> x >> y >> r;
        cir[y-r].eb(y+r, x);

        xvals.ep(x);
        yvals.ep(y-r);
    }

    map<int, vector<tuple<int, int, int, int> > > quer;
    for(int i=0; i<q; ++i){
        int x1, y1, x2, y2, lo, hi;
        cin >> x1 >> y1 >> x2 >> y2 >> lo >> hi;
        quer[lo].eb(hi, min(x1, x2), max(x1, x2), i);

        xvals.ep(x1);
        xvals.ep(x2);
        yvals.ep(lo);
    }

    int k = 0;
    map<int, int> compx;
    for(int i:xvals)
        compx[i] = k++;

    vb ans(q);
    SegTree<RMaxQ, int> st(vi(k, -LINF));
    for(int y:yvals){
        if(cir.count(y)){
            for(auto [hi, x]:cir[y]){
                x = compx[x];

                int v = st.query(x);
                if(v >= hi)
                    continue;
                st.update(x, hi-v);
            }
        }
        if(quer.count(y)){
            for(auto [hi, x1, x2, i]:quer[y]){
                x1 = compx[x1];
                x2 = compx[x2];

                int v = st.query(x1, x2);
                if(v >= hi)
                    ans[i] = false;
                else
                    ans[i] = true;
            }
        }
    }
    for(int i=0; i<q; ++i)
        cout << (ans[i]? "YES" : "NO") << endl;
    return 0;
}
