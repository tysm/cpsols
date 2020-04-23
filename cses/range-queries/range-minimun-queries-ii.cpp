#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1649
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(auto &i:arr)
        cin >> i;
    SegTree<SegTreeKind::RMinQ, int> st(arr);
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
