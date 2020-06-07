#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    int ans = 0;
    for(int i=0; i<n; ++i){
        ans = max(ans, arr[i]);
        for(int j=i+1; j<n; ++j){
            ans = max(ans, arr[i] | arr[j]);
            for(int k=j+1; k<n; ++k)
                ans = max(ans, arr[i] | arr[j] | arr[k]);
        }
    }
    cout << ans << endl;
    return 0;
}
