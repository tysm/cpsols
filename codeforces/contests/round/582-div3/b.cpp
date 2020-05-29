#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        for(int i=0; i<n; ++i)
            cin >> v[i];
        int ans = 0, aux = INF;
        for(int i=n-1; i>=0; --i){
            if(v[i] > aux)
                ans++;
            aux = min(v[i], aux);
        }
        cout << ans << endl;
    }
    return 0;
}
