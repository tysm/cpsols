#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>

// 4: 1 2 3 4
// 2: 0 -1 -> -1 0 3 4

int32_t main(){
    desync();
    int n, m, q;
    cin >> n >> m >> q;

    vii arr(n);
    for(int i=0; i<n; ++i){
        cin >> arr[i].ff;
        arr[i].ss = i;
    }
    int idx = -1, val = arr[0].ff;

    sort(all(arr));
    for(int i=0; i<n; ++i){
        if(arr[i].ss == 0)
            idx = i;
    }

    vi pos(m+1);
    vvi B(m);
    for(int i=0; i<m; ++i){
        int k;
        cin >> k;

        idx -= k;
        pos[i] = idx;

        B[i].resize(k);
        for(int &j:B[i]){
            cin >> j;
            if(j < val)
                idx++;
        }
    }
    SegTree<RMinQ, int> st(pos);

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;

        if(B[x][y] < val)
            st.update(x+1, m, -1);
        if(z < val)
            st.update(x+1, m, 1);
        B[x][y] = z;

        int res = st.query(0, m-1);
        if(res < 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
