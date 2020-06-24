#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics/binomial-coefficient.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int m = n + (n-1), acc = 0;
    while(acc*10 + 9 <= m){
        acc *= 10;
        acc += 9;
    }
    if(acc == 0)
        cout << binc(n, 2) << endl;
    else{
        int ans = min(n, acc-1) - acc/2;
        for(int i=1; i<9; ++i){
            int v = i;
            while(v < acc){
                v *= 10;
                v += 9;
            }
            if(v <= m)
                ans += min(n, v-1) - v/2;
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
