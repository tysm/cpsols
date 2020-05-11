#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1662
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    // (sum(r)-sum(l-1))%n == 0
    // sum(r)-sum(l-1) == n*(0...)
    // sum(r) == n*(0...) + sum(l-1)
    // sum(r)%n == (n*(0...))%n + sum(l-1)%n
    // sum(r)%n == sum(l-1)%n
    int summod = 0, ans = 0;
    map<int, int> sumlmod; sumlmod[0]++;
    for(int i=0; i<n; ++i){
        summod = mod(summod + arr[i], n);
        ans += sumlmod[summod];
        sumlmod[summod]++;
    }
    cout << ans << endl;
    return 0;
}
