#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k, sum = 0;
    cin >> n >> k;

    vi arr(n);
    for(int i=0; i<k; ++i){
        int a, b;
        cin >> a >> b;
        sum += b;

        arr[a-1] = b;
    }
    if(sum < n){
        cout << 1 << endl;
        return 0;
    }
    if(sum > n){
        cout << -1 << endl;
        return 0;
    }
    bool ok = (n == k);
    cout << (ok? 1 : -1) << endl;
    return 0;
}
