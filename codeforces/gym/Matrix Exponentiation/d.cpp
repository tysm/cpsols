#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    matrix<mint, 100> single(0);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        single[u][v] = 1;
    }
    auto res = exp(single, k);
    mint ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            ans += res[i][j];
    }
    cout << ans << endl;
    return 0;
}
