#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, s;
    cin >> n >> s;
    s *= 100;

    int ans = -1;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;

        int cost = x*100 + y;
        if(cost > s)
            continue;
        ans = max(ans, (s-cost)%100);
    }
    cout << ans << endl;
    return 0;
}
