#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtreeb.hpp>

struct Node:STNodeB<double>
{
    Node()
    {
        this->value = 0;
    }

    Node(const double value)
    {
        this->value = value;
    }

    Node(const Node &lhs, const Node &rhs)
    {
        this->value = lhs.value + rhs.value;
    }

    void update(const size_t range)
    {
        this->value += range*this->lazy;
        this->lazy = 0;
    }
};

int flatten(vvi &adj, vii &ntor, int u, int l, int p){
    int r = l;
    for(int v:adj[u]){
        if(v == p)
            continue;
        r = flatten(adj, ntor, v, r+1, u);
    }
    ntor[u] = {l, r};
    return r;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    vii ntor(n);
    flatten(adj, ntor, 0, 0, -1);

    SegTreeB<Node, double> st(n);

    int q;
    cin >> q;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            x--;
            x = ntor[x].ff;
            double cur = st.query(x);
            st.update(x, log10(y)-cur);
        }
        else{
            x--;
            y--;
            double resx = st.query(ntor[x].ff, ntor[x].ss);
            double resy = st.query(ntor[y].ff, ntor[y].ss);
            cout << fixed << setprecision(10);
            if(resx-resy >= log10(1e9) + EPS)
                cout << 1e9 << endl;
            else
                cout << pow(10, resx-resy) << endl;
        }
    }
    return 0;
}
