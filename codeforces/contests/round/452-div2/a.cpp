#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int a = 0, b = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x == 1)
            a++;
        else
            b++;
    }
    int ans = a/3;
    for(int i=1; i<=min(a, b); ++i)
        ans = max(ans, i + (a - i)/3);
    cout << ans << endl;
    return 0;
}
