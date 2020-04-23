#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1143
    desync();
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for(int &h:arr)
        cin >> h;
    SegTree<SegTreeKind::RMaxQ, int> st(arr);
    for(int i=0; i<m; ++i){
        int r;
        cin >> r;
        int ans = st.find(r);
        if(ans != n)
            st.update(ans, -r);
        if(i)
            cout << ' ';
        cout << (ans == n? 0 : ans + 1);
    }
    cout << endl;
    return 0;
}
