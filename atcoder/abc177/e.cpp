#include <cpplib/stdinc.hpp>
#include <cpplib/math/euclid.hpp>
#include <cpplib/math/gries-misra.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;
    reverse(all(arr));

    int g = arr[0];
    for(int i=1; i<n; ++i)
        g = gcd(arr[i], g);
    if(g > 1){
        cout << "not coprime" << endl;
        return 0;
    }

    Sieve sv(1e6+1);
    set<int> vis;
    bool ok = true;
    for(int i=0; i<n and ok; ++i){
        for(auto [f, cnt] : sv.factorization(arr[i])){
            if(vis.count(f))
                ok = false;
            vis.ep(f);
        }
    }
    cout << (ok? "pairwise coprime" : "setwise coprime") << endl;
    return 0;
}
