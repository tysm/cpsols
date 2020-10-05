#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, m, q;
    cin >> n >> m >> q;

    matrix<mint, 200> adj(0);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1][v-1] = 1;
    }

    vector<matrix<mint, 200> > prec;
    prec.eb(adj);
    for(int i=2, j=0; i<=1e9; i<<=1, ++j)
        prec.eb(prec[j]*prec[j]);

    while(q--){
        int u, v, k;
        cin >> u >> v >> k;

        matrix<mint, 1, 200> ans(0);
        ans[0][u-1] = 1;
        for(int i=0; i<prec.size(); ++i){
            if(k & (1<<i))
                ans = ans*prec[i];
        }
        cout << ans[0][v-1] << endl;
    }
    return 0;
}
