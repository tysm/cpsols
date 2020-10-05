#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtreeb.hpp>

struct Node : STNodeB<int>
{
    Node() : Node(-1) {}

    Node(const int value) : STNodeB(value) {}

    Node(const Node &lhs, const Node &rhs)
    {
        this->value = lhs.value & rhs.value;
    }

    void update(const size_t range)
    {
        this->value |= this->lazy;
        this->lazy = 0;
    }

    void update_lazy(const int delta)
    {
        this->lazy |= delta;
    }
};

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    SegTreeB<Node, int> st(vi(n, 0));
    vtt q;
    for(int i=0; i<m; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        st.update(l-1, r-1, x);
        q.eb(l-1, r-1, x);
    }
    bool ok = true;
    for(int i=0; i<m; ++i){
        int l, r, x;
        tie(l, r, x) = q[i];
        if(x != st.query(l, r))
            ok = false;
    }
    if(ok){
        cout << "YES" << endl;
        for(int i=0; i<n; ++i)
            cout << st.query(i) << " \n"[i == n-1];
    }
    else
        cout << "NO" << endl;
    return 0;
}
