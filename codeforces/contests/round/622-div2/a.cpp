#include <cpplib/stdinc.hpp>

int solve(int a, int b, int c){
    int ans = 0;
    if(a){
        ans++;
        a--;
    }
    if(b){
        ans++;
        b--;
    }
    if(c){
        ans++;
        c--;
    }
    if(a and b){
        ans++;
        a--;
        b--;
    }
    if(a and c){
        ans++;
        a--;
        c--;
    }
    if(b and c){
        ans++;
        b--;
        c--;
    }
    if(a and b and c){
        ans++;
        a--;
        b--;
        c--;
    }
    return ans;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = solve(a, b, c);
        ans = max(ans, solve(a, c, b));
        ans = max(ans, solve(b, a, c));
        ans = max(ans, solve(b, c, a));
        ans = max(ans, solve(c, a, b));
        ans = max(ans, solve(c, b, a));
        cout << ans << endl;
    }
    return 0;
}
