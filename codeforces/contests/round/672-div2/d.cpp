#include <cpplib/stdinc.hpp>
#undef MOD
#define MOD ((int)998244353)
#include <cpplib/adt/modular.hpp>
#include <cpplib/math/modc.hpp>

int32_t main(){
    desync();
    ModC<> comb(3e5+1);
    int n, k;
    cin >> n >> k;

    set<int> ops;
    map<int, int> on, off;
    for(int i=0; i<n; ++i){
        int l, r;
        cin >> l >> r;
        on[l]++;
        off[r+1]++;
        ops.ep(l);
        ops.ep(r+1);
    }

    int cur = 0;
    mint ans = 0;
    for(int i:ops){
        cur -= off[i];

        for(int j=1; j<=min(on[i], k); ++j){
            int d = k-j;
            if(cur >= d)
                ans += comb.C(on[i], j)*comb.C(cur, d);
        }
        cur += on[i];
    }
    cout << ans << endl;
    return 0;
}
