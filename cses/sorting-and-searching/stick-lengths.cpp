#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1074
    desync();
    int n;
    cin >> n;

    vi sticks(n);
    for(int &i:sticks)
        cin >> i;
    sort(sticks.begin(), sticks.end());

    vi ic(n), dc(n);
    for(int i=1; i<n; ++i){
        ic[i] = ic[i-1] + (sticks[i]-sticks[i-1])*i;
        int j = n-i-1;
        dc[j] = dc[j+1] + (sticks[j+1]-sticks[j])*i;
    }
    int ans = n*INF;
    for(int i=0; i<n; ++i)
        ans = min(ans, ic[i]+dc[i]);
    cout << ans << endl;
    return 0;
}
