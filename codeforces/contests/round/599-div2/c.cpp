#include <cpplib/stdinc.hpp>
#include <cpplib/math/gries-misra.hpp>

int32_t main(){
    desync();
    Sieve sv(1e6+1);
    int n;
    cin >> n;
    int ans = -1;
    for(int i=2; i*i<=n and ans == -1; ++i){
        if(n%i == 0){
            if(!sv.is_prime(i))
                ans = 1;
            else{
                while(n%i == 0  and n > 1)
                    n /= i;
                if(n == 1)
                    ans = i;
                else
                    ans = 1;
            }
        }
    }
    if(ans == -1)
        cout << n << endl;
    else
        cout << ans << endl;
    return 0;
}
