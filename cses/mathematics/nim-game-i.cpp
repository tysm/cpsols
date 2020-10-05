#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1730
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        int res = arr[0];
        for(int i=1; i<n; ++i)
            res ^= arr[i];
        if(res)
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    return 0;
}
