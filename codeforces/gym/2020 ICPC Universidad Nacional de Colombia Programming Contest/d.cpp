#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int a, k;
    cin >> a >> k;
    debug(a, k);

    mint ans = 0, cur = 1;

    vector<mint> dp(k);
    for(int i=0; i<k; ++i){
        cur *= a;
        dp[k] = cur;

        ans += cur;
        int dif = k - (i+1);
        ans -= (dif/(i+1))*cur;
        if(dif%(i+1))
            ans -= dp[dif%(i+1) - 1];
    }
    cout << ans << endl;
    return 0;
}
