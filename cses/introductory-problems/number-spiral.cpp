#include <cpplib/stdinc.hpp>

int solve(int i, int j){
    int l = max(i, j), ans = l*l;
    if(l%2 == 0){
        ans -= 2*(l-1);
        ans += i-1+l-j;
    }
    else
        ans -= i-1+l-j;
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1071
    desync();
    int t;
    cin >> t;
    while(t--){
        int i, j;
        cin >> i >> j;
        cout << solve(i, j) << endl;
    }
    return 0;
}
