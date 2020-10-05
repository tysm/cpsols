#include <cpplib/stdinc.hpp>
#include <cpplib/math/modc.hpp>

int32_t main(){
    desync();
    ModC<> modc(1e5+3);

    int t;
    cin >> t;
    while(t--){
        mint oth = 1;

        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr){
            cin >> i;
            oth *= i;
        }

        mint ans = 0;
        for(int i=0; i<n; ++i){
            mint oi = oth*modc.inv(arr[i]);
            ans += oi*(arr[i]-1);
        }
        cout << ans << endl;
    }
    return 0;
}
