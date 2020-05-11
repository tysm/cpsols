#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1660
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    int acc = arr[0], i = 0, j = 1, ans = (arr[0] == k);
    while(i < n){
        if(j < n and (acc < k or i == j))
            acc += arr[j++];
        else
            acc -= arr[i++];
        ans += (acc == k);
    }
    cout << ans << endl;
    return 0;
}
