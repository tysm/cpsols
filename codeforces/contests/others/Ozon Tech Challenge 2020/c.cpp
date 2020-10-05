#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    if(n <= m){
        int ans = 1;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j)
                ans = (ans*(abs(arr[i]-arr[j])%m))%m;
        }
        cout << ans << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}
