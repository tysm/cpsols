#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>
#include <cpplib/data-structure/tree/segment-tree-2d.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for(auto &i:s)
        cin >> i;
    vvi mat(n, vi(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            mat[i][j] = (s[i][j] == '*');
    }
    SegTree2D<SegTreeKind::RSumQ, int> st(mat);
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << st.query(y1-1, y2-1, x1-1, x2-1) << endl;
    }
    return 0;
}
