#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1084
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    vi apl(n);
    for(int &i:apl)
        cin >> i;
    sort(apl.begin(), apl.end());

    vi aps(m);
    for(int &i:aps)
        cin >> i;
    sort(aps.begin(), aps.end());

    int i = 0, j = 0, ans = 0;
    while(i<n and j<m){
        if(apl[i] - k <= aps[j] and aps[j] <= apl[i] + k){
            ans++;
            i++;
            j++;
        }
        else if(aps[j] < apl[i])
            j++;
        else
            i++;
    }
    cout << ans << endl;
    return 0;
}
