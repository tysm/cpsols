#include <cpplib/header.hpp>
#include <cpplib/data-structures/trees/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1650
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(auto &i:arr)
        cin >> i;
    SegTree<SegTreeKind::RXorQ, int> st(arr);
    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << st.query(a, b) << endl;
    }
    return 0;
}
