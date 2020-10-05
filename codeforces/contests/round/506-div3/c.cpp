#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    multiset<int> l, r;
    vii arr(n);
    for(ii &i:arr){
        cin >> i.ff >> i.ss;
        l.emplace(-i.ff);
        r.emplace(i.ss);
    }
    int ans = max((int)0, *r.begin() + *l.begin());
    for(int i=0; i<n; ++i){
        l.erase(l.lower_bound(-arr[i].ff));
        r.erase(r.lower_bound(arr[i].ss));
        ans = max(ans, *r.begin() + *l.begin());
        l.emplace(-arr[i].ff);
        r.emplace(arr[i].ss);
    }
    cout << ans << endl;
    return 0;
}
