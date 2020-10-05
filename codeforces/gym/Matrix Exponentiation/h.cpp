#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>
#include <cpplib/adt/segtreeb.hpp>

struct Node : STNodeB<matrix<mint, 2> > {
    Node()
    {
        this->value.fill(0);
    }

    Node(const matrix<mint, 2> &value)
    {
        this->value = value;
    }

    Node(const Node &lhs, const Node &rhs) :
        Node(lhs.value*rhs.value) {}

    void update(const size_t range)
    {
        this->value += this->lazy;
        this->lazy.fill(0);
    }
};

matrix<mint, 2> ctm(char c){
    matrix<mint, 2> res(0);
    switch(c){
        case '?':
            res[0][0] = 1 + 18;
            res[0][1] = 2 + 5;
            res[1][0] = 1 + 5;
            res[1][1] = 2 + 18;
            break;
        case 'H':
            res[0][0] = res[1][0] = 1;
            break;
        case 'S': case 'D':
            res[0][1] = res[1][1] = 1;
            break;
        case 'A': case 'E': case 'I': case 'O': case 'U':
            res[0][1] = res[1][0] = 1;
            break;
        default:
            res[0][0] = res[1][1] = 1;
    }
    return res;
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<matrix<mint, 2> > arr;
    for(char c:s)
        arr.eb(ctm(c));

    SegTreeB<Node, matrix<mint, 2> > st(arr);
    auto res = st.query(0, n-1);
    cout << res[0][0] << endl;
    while(q--){
        int idx;
        char c;
        cin >> idx >> c;

        auto val = ctm(c);
        st.update(idx-1, val - arr[idx-1]);
        arr[idx-1] = val;

        res = st.query(0, n-1);
        cout << res[0][0] << endl;
    }
    return 0;
}
