#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

struct Node : STNodeSB<int> {
    using super_type = STNodeSB<int>;
    int sum = 0, mpsum = 0, mssum = 0;

    Node() : super_type(0) {}

    Node(int val) :
        super_type(max(val, 0LL)), sum(val), mpsum(max(val, 0LL)), mssum(max(val, 0LL)) {}

    Node(const Node &l, const Node &r) :
        super_type(max({l.value, r.value, l.mssum+r.mpsum}))
    {
        sum = l.sum+r.sum;
        mpsum = max(l.mpsum, l.sum+r.mpsum);
        mssum = max(l.mssum+r.sum, r.mssum);
    }

    bool match(const int value) const { return value; }

    void update(const size_t range)
    {
        if(this->set.ss)
            sum = this->set.ff;
        sum += this->lazy;

        this->value = mpsum = mssum = max(sum, 0LL);

        this->lazy = 0;
        this->set = {0, false};
    }
};

int32_t main(){
    // https://cses.fi/problemset/task/1190
    desync();
    int n, m;
    cin >> n >> m;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    SegTreeSB<Node, int> st(arr);
    while(m--){
        int k, x;
        cin >> k >> x;
        st.set(k-1, x);
        cout << st.query(0, n-1) << endl;
    }
    return 0;
}
