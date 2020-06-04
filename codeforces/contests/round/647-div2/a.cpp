#include <cpplib/stdinc.hpp>



int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n == m){
            cout << 0 << endl;
            continue;
        }
        int x = 0;
        if(n <= m and m%n == 0)
            x = m/n;
        else if(m <= n and n%m == 0)
            x = n/m;
        int cnt = 0;
        while(x > 1 and x%2 == 0){
            cnt++;
            x /= 2;
        }
        if(x > 1 or !x)
            cout << -1 << endl;
        else{
            int ans = 0;
            ans += cnt/3;
            cnt %= 3;
            ans += cnt/2;
            cnt %= 2;
            ans += cnt;
            cout << ans << endl;
        }
    }
    return 0;
}
