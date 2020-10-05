#include <cpplib/stdinc.hpp>

vi repr, ans;
int get_repr(int u){
    if(u == repr[u])
        return u;
    int r = repr[u];
    int res = get_repr(repr[u]);
    ans[u] += ans[r];
    return repr[u] = res;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    repr.resize(n);
    iota(all(repr), 0);
    ans.resize(n);

    for(int i=0; i<m; ++i){
        int op;
        cin >> op;

        if(op == 1){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            repr[u] = get_repr(v);
            ans[u] = ans[v]+1;
        }
        else{
            int u;
            cin >> u;
            u--;
            get_repr(u);
            cout << ans[u] << endl;
        }
    }
    return 0;
}
