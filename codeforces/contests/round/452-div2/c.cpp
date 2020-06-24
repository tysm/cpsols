#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int sum = ((n+1)*n)/2;
    cout << sum%2 << endl;
    sum = sum/2 + sum%2;
    vi ans;
    for(int i=n; i>=1; --i){
        if(i > sum)
            continue;
        sum -= i;
        ans.pb(i);
    }
    reverse(all(ans));
    cout << ans.size();
    for(int i:ans)
        cout << ' ' << i;
    cout << endl;
    return 0;
}
