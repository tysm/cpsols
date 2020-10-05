#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>

mint solve(int x){
    int cur = 0, op = 1, e = false;
    mint odd = 0, even = 0;
    while(cur+op <= x){
        if(e)
            even += op;
        else
            odd += op;
        cur += op;
        op *= 2;
        e ^= 1;
    }
    if(e)
        even += x-cur;
    else
        odd += x-cur;
    mint res = 0;
    res += (1 + 2*odd-1)*odd/2;
    res += (2 + 2*even)*even/2;
    return res;
}

int32_t main(){
    desync();
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l-1) << endl;
    return 0;
}
