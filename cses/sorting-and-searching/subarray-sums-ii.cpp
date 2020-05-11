#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1661
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    // k = sum(r) - sum(l-1)
    // sum(r) = k + sum(l-1)
    // sum(l-1) = sum(r) - k
    int sum = 0, ans = 0;
    map<int, int> suml; suml[0]++;
    for(int i=0; i<n; ++i){
        sum += arr[i];
        ans += suml[sum-k];
        ++suml[sum];
    }
    cout << ans << endl;
    return 0;
}
