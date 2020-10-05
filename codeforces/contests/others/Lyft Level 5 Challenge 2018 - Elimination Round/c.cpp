#include <cpplib/stdinc.hpp>

int n;
vi arr, dp;

int solve(int i){
    int &res = dp[i];
    if(res == -1){
        res = false;
        for(int j = i+arr[i]; j<n; j+=arr[i]){
            if(arr[j] < arr[i])
                continue;
            res |= !solve(j);
        }
        for(int j = i-arr[i]; j>=0; j-=arr[i]){
            if(arr[j] < arr[i])
                continue;
            res |= !solve(j);
        }
    }
    return res;
}

int32_t main(){
    desync();
    cin >> n;
    arr.resize(n);
    dp.resize(n, -1);
    for(int &i:arr)
        cin >> i;
    for(int i=0; i<n; ++i)
        cout << (solve(i)? 'A' : 'B');
    cout << endl;
    return 0;
}
