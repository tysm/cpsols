#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

int32_t main(){
    desync();
    Sieve sv(1e7);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<uint, uint> > > num, den;
    map<int, int> cnt;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        num.pb(sv.factorization(x));
        for(ii f:num[i])
            cnt[f.ff] += f.ss;
    }
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        den.pb(sv.factorization(x));
        for(ii f:den[i])
            cnt[f.ff] -= f.ss;
    }
    cout << n << ' ' << m << endl;
    for(int i=0; i<n; ++i){
        if(i)
            cout << ' ';
        int x = 1;
        for(ii f:num[i]){
            if(cnt[f.ff] <= 0)
                continue;
            int t = min(cnt[f.ff], f.ss);
            f.ss -= t;
            cnt[f.ff] -= t;
            x *= bexp(f.ff, t);
        }
        cout << x;
    }
    cout << endl;
    for(int i=0; i<m; ++i){
        if(i)
            cout << ' ';
        int x = 1;
        for(ii f:den[i]){
            if(cnt[f.ff] >= 0)
                continue;
            int t = min(-cnt[f.ff], f.ss);
            f.ss -= t;
            cnt[f.ff] += t;
            x *= bexp(f.ff, t);
        }
        cout << x;
    }
    cout << endl;
    return 0;
}
