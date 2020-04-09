#include <cpplib/stdinc.hpp>

int solve(vi &arr, int n, int i, int dif = 0){
    if(i == n)
        return abs(dif);
    return min(solve(arr, n, i+1, dif+arr[i]), solve(arr, n, i+1, dif-arr[i]));
}

int32_t main(){
    // https://cses.fi/problemset/task/1623
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    cout << solve(arr, n, 0) << endl;
    return 0;
}
