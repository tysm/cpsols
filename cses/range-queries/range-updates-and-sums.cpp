#include <cpplib/stdinc.hpp>
#include <cpplib/data-structures/trees/segment-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1735
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
        else if (x == 2){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            st.set(a, b, c);
        }
        else{
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << st.query(a, b) << endl;
        }
    }
    return 0;
}
