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
        sort(arr.begin(), arr.end());
        int odd = 0, s = 0;
        for(int i=0; i<n; ++i){
            if(i)
                s += (arr[i]-arr[i-1] == 1);
            odd += arr[i]%2;
        }
        if(odd%2 == 0 or s > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
