#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>
#include <cpplib/data-structure/tree/segment-tree-2d.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1739
    desync();
    int n, q;
    cin >> n >> q;
    vvi arr(n, vi(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char c;
            cin >> c;
            arr[i][j] = (c == '*');
        }
    }
    SegTree2D<RSumQ, int> st(arr);
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int y, x;
            cin >> y >> x;
            y--; x--;
            st.update(y, x, (arr[y][x] ^ 1) - arr[y][x]);
            arr[y][x] ^= 1;
        }
        else{
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << st.query(y1-1, y2-1, x1-1, x2-1) << endl;
        }
    }
    return 0;
}
