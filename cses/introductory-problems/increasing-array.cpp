#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1094
    // desync();
    int n, cur, last = 0, ans = 0;
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &cur);
        if(last > cur){
            ans += last - cur;
            cur = last;
        }
        last = cur;
    }
    printf("%lld\n", ans);
    return 0;
}
