#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    map<int, int> aux;
    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;
        aux[i-x] += x;
    }
    int ans = 0;
    for(ii i:aux)
        ans = max(ans, i.ss);
    cout << ans << endl;
    return 0;
}
