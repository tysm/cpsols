#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        sort(all(arr));
        bool ok = true;
        for(int i=1; i<n; ++i){
            if(arr[i] - arr[i-1] > 1)
                ok = false;
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}
