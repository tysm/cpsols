#include <cpplib/header.hpp>
#include <cpplib/data-structures/trees/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1648
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(auto &i:arr)
        cin >> i;
    SegTree<SegTreeKind::RSumQ, int> st(arr);
    while(q--){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 2)
            cout << st.query(a-1, b-1) << endl;
        else{
            st.update(a-1, b-arr[a-1]);
            arr[a-1] = b;
        }
    }
    return 0;
}
