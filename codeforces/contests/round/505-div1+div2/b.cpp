#include <cpplib/stdinc.hpp>
#include <cpplib/math/wheel.hpp>

bool check(int p, vii &arr){
    for(ii &i:arr){
        if(i.ff%p and i.ss%p)
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vii arr(n-1);
    for(int i=0; i<n-1; ++i)
        cin >> arr[i].ff >> arr[i].ss;
    set<int> f;
    for(const ii &pf:factorization(a))
        f.emplace(pf.ff);
    for(const ii &pf:factorization(b))
        f.emplace(pf.ff);
    int ans = -1;
    for(int pf:f){
        if(check(pf, arr)){
            ans = pf;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
