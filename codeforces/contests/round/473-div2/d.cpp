#include <cpplib/stdinc.hpp>
#include <cpplib/math/gries-misra.hpp>

int32_t main(){
    desync();
    Sieve sv(MAXN);

    set<int> ok;
    for(int i=2; i<=MAXN; ++i)
        ok.ep(i);


    int n;
    cin >> n;

    vi ans(n);
    bool lg = false;
    for(int i=0; i<n; ++i){
        cin >> ans[i];
        if(lg)
            ans[i] = *ok.begin();
        else{
            int x = *ok.lower_bound(ans[i]);
            if(x > ans[i])
                lg = true;
            ans[i] = x;
        }

        for(auto [f, cnt]:sv.factorization(ans[i])){
            for(int p=f; p<=MAXN; p+=f)
                ok.erase(p);
        }
    }
    cout << ans << endl;

    return 0;
}
