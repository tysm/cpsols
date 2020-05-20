#include <cpplib/stdinc.hpp>

bool solve(int n, int k, vi &arr){
    bool possible = false;
    for(int &i:arr){
        if(i < k)
            i = 0;
        else if(i == k)
            i = possible = true;
        else
            i = 2;
    }
    if(!possible)
        return false;
    if(n == 1)
        return true;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n and j-i <= 2; ++j){
            if(arr[i] and arr[j])
                return true;
        }
    }
    return false;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        if(solve(n, k, arr))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
