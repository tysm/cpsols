#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        while(n >= 10){
            ans += n - n%10;
            n = n%10 + n/10;
        }
        cout << ans+n << endl;
    }
    return 0;
}
