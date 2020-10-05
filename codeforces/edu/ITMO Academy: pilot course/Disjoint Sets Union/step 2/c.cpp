#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

vi repr;
int get_repr(int u){
    return u == repr[u]? u : repr[u] = get_repr(repr[u]);
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    repr.resize(n);
    iota(all(repr), 0);

    DSU dsu(n);

    while(q--){
        int op, u, v;
        cin >> op >> u >> v;
        u--;
        v--;
        if(get_repr(v) < get_repr(u))
            swap(u, v);

        if(op == 1){
            int ru = get_repr(u), rv = get_repr(v);
            if(dsu.merge(u, v)){
                if(get_repr(ru+1) == rv)
                    repr[ru] = rv;
            }
        }
        else if(op == 2){
            int ru = get_repr(u), rv = get_repr(v);
            while(ru < rv){
                int ru1 = get_repr(ru+1);
                dsu.merge(ru, ru1);
                repr[ru] = ru1;
                ru = ru1;
            }
        }
        else
            cout << (dsu.same(u, v)? "YES" : "NO") << endl;
    }
    return 0;
}
