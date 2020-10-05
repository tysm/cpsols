#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics/modular.hpp>

int32_t main(){
    desync();
    ModC<> combs;

    int h, w, n;
    cin >> h >> w >> n;
    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;
    sort(all(arr));

    mint ans = combs.C(h + w - 2, h - 1);
    vector<mint> res(n);
    for(int i=n-1; i>=0; --i){
        ii pi = arr[i];
        mint ways = combs.C(h - pi.ff + w - pi.ss, h - pi.ff);
        for(int j=i+1; j<n; ++j){
            ii pj = arr[j];
            if(pi.ff > pj.ff or pi.ss > pj.ss)
                continue;
            mint wto = combs.C(pj.ff - pi.ff + pj.ss - pi.ss, pj.ff - pi.ff);
            ways -= wto*res[j];
        }
        res[i] = ways;
        ans -= ways*combs.C(pi.ff + pi.ss - 2, pi.ff - 1);
    }
    cout << ans << endl;
    return 0;
}
