#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vii arr(n, {-1, -1});
    for(ii &i:arr)
        cin >> i.ff;
    int q;
    cin >> q;
    SegTreeS<RMaxQ, int> st(q+1);
    st.set(0, q-1, 0);
    for(int i=0; i<q; ++i){
        int op;
        cin >> op;
        if(op == 1){
            int p, x;
            cin >> p >> x;
            arr[p-1] = {x, i};
        }
        else{
            int x;
            cin >> x;
            st.set(i, x);
        }
    }
    for(int i=0; i<n; ++i){
        if(i)
            cout << ' ';
        cout << max(arr[i].ff, st.query(arr[i].ss+1, q));
    }
    cout << endl;
    return 0;
}
