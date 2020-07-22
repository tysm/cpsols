#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        int acc = 0, flag = 0;
        for(int i=1; i<=n; ++i){
            cin >> arr[i-1];
            if(arr[i-1] == i)
                flag = 0;
            else if(!flag){
                flag = 1;
                acc++;
            }
        }
        if(acc == 0)
            cout << 0 << endl;
        else if(acc == 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
