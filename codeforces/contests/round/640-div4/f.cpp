#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string ans;
        if(n1){
            for(int i=0; i<=n2; ++i)
                ans += '1';
            for(int i=0; i<n0; ++i)
                ans += '0';
            for(int i=0; i<n1; ++i)
                ans += '0' + i%2;
        }
        else if(n2){
            for(int i=0; i<=n2; ++i)
                ans += '1';
        }
        else{
            for(int i=0; i<=n0; ++i)
                ans +=  '0';
        }
        cout << ans << endl;
    }
    return 0;
}
