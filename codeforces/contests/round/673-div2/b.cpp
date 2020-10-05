#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, T;
        cin >> n >> T;

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        map<int, int> clr;
        for(int i=0; i<n; ++i){
            if(clr.count(T-arr[i]))
                clr[arr[i]] = (clr[T-arr[i]]^1);
            else
                clr[arr[i]] = 0;
            cout << clr[arr[i]] << " \n"[i == n-1];
        }
    }
    return 0;
}
