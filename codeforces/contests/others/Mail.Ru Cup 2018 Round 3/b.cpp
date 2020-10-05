#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<m; ++j){
            if((i*i + j*j)%m or n-i < 0 or n-j < 0)
                continue;
            ans += ((n-i)/m + (i != 0))*((n-j)/m + (j != 0));
        }
    }
    cout << ans << endl;
    return 0;
}
