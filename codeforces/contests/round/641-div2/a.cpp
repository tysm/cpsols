#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=2; i<=n; ++i){
            if(n%i == 0){
                n += i;
                break;
            }
        }
        cout << n + (k-1)*2 << endl;
    }
    return 0;
}
