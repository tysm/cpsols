#include <cpplib/stdinc.hpp>

int32_t main(){
    int n, k, s;
    cin >> n >> k >> s;
    vi ans;
    int cur = 1;
    while(s > 0 and k > 0){
        if(s <= k){
            if(cur+1 <= n)
                cur++;
            else
                cur--;
            s--;
        }
        else{
            int d = min({n-1, s-(k-1), max(abs(n-cur), abs(1-cur))});
            if(cur+d <= n)
                cur+=d;
            else
                cur-=d;
            s -= d;
        }
        ans.eb(cur);
        k--;
    }
    if(!s and !k){
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
