#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>
#include <cpplib/math/modc.hpp>

#undef MOD
#define MOD ((int)998244353)

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi arr(n+2);

    vii rng(n);
    for(ii &i:rng){
        cin >> i.ff >> i.ss;
        arr[i.ff]++;
        arr[i.ss+1]--;
    }

    vii edges(m);
    for(ii &i:edges){
        cin >> i.ff >> i.ss;
        i.ff--;
        i.ss--;
    }

    for(int i=1, cur = 0; i<=n; ++i){
        cur += arr[i];
        arr[i] = cur;
    }
    arr[n+1] = 0;

    ModC<MOD> modc(n);

    vector<vector<modular<MOD> > > psum(2*m+1);
    for(int p=0; p<=2*m; ++p){
        for(int k=0; k<=n; ++k){
            if(arr[k]-p >= k-p and k-p >= 0)
                psum[p].eb(modc.C(arr[k]-p, k-p));
            else
                psum[p].eb(0);
            if(k)
                psum[p][k] += psum[p][k-1];
        }
    }

    modular<MOD> ans = psum[0][n] - psum[0][0];
    for(int b=1; b<(1<<m); ++b){
        int l = 1, r = n;
        set<int> cur;
        for(int i=0; i<m; ++i){
            if(b & (1<<i)){
                cur.ep(edges[i].ff);
                cur.ep(edges[i].ss);
                l = max({l, rng[edges[i].ff].ff, rng[edges[i].ss].ff});
                r = min({r, rng[edges[i].ff].ss, rng[edges[i].ss].ss});
            }
        }
        modular<MOD> res = 0;
        if(l <= r)
            res = psum[cur.size()][r] - psum[cur.size()][l-1];
        if(__builtin_popcount(b) & 1)
            ans -= res;
        else
            ans += res;
    }
    cout << ans << endl;
    return 0;
}
