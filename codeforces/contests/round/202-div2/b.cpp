#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = 0;
    vi arr(9);
    for(int i=0; i<9; ++i){
        cin >> arr[i];
        if(arr[i] <= arr[ans])
            ans = i;
    }
    if(arr[ans] > n)
        cout << -1 << endl;
    else{
        vi res(n/arr[ans], ans);
        int cur = n - n%arr[ans];
        for(int i=0; i<res.size(); ++i){
            for(int j=8; j>ans; --j){
                if(cur-arr[ans]+arr[j] <= n){
                    cur -= arr[ans];
                    cur += arr[j];
                    res[i] = j;
                    break;
                }
            }
        }
        for(int i:res)
            cout << i+1;
        cout << endl;
    }
    return 0;
}
