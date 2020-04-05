#include <cpplib/stdinc.hpp>
#include <cpplib/data-structures/trees/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1651
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(auto &i:arr)
        cin >> i;
    SegTree<SegTreeKind::RSumQ, int> st(arr);
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            st.update(a, b, c);
        }
        else{
            int i;
            cin >> i;
            cout << st.query(i-1) << endl;
        }
    }
    return 0;
}
