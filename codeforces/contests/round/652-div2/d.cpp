#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    vi ans(2*MAX);
    ans[3] = 1;
    for(int i=4; i<2*MAX; ++i)
        ans[i] = mod(ans[i-1] + mod(2*ans[i-2]) + (i%3 == 0));
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << mod(4*ans[n]) << endl;
    }
    return 0;
}
