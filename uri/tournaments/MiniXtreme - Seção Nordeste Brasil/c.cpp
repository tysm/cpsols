#include <cpplib/stdinc.hpp>

int32_t main(){
    int n;
    while(cin >> n){
        vi idx(n);
        for(int &i:idx)
            cin >> i;
        vi tim(n);
        for(int &t:tim)
            cin >> t;
        int ans = 0;
        for(int j=0; j<n-1; ++j){
            for(int i=0; i<n-1; ++i){
                if(idx[i] > idx[i+1]){
                    swap(idx[i], idx[i+1]);
                    swap(tim[i], tim[i+1]);
                    ans += tim[i] + tim[i+1];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
