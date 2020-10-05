#include <cpplib/stdinc.hpp>
#include <cpplib/math/modc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1078/.
    desync();
    ModC<> combs(3*MAXN);

    int n, m
    cin >> n >> m;
    vii arr(m);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;
    sort(all(arr));

    mint ans = combs.C(2*n - 2, n - 1);
    vector<mint> res(m);
    for(int i=m-1; i>=0; --i){
        ii pi = arr[i];
        mint ways = combs.C(2*n - pi.ff - pi.ss, n - pi.ff);
        for(int j=i+1; j<m; ++j){
            ii pj = arr[j];
            if(pi.ff > pj.ff or pi.ss > pj.ss)
                continue;
            ways -= res[j]*combs.C(pj.ff - pi.ff + pj.ss - pi.ss, pj.ff - pi.ff);
        }
        res[i] = ways;
        ans -= ways*combs.C(pi.ff + pi.ss - 2, pi.ff - 1);
    }
    cout << ans << endl;
    return 0;
}
