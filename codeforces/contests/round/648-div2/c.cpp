#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi pos(n+1);
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        pos[a] = i;
    }
    map<int, int> cnt;
    for(int i=0; i<n; ++i){
        int b;
        cin >> b;
        cnt[mod(pos[b]-i, n)]++;
    }
    int ans = 0;
    for(ii i:cnt)
        ans = max(i.ss, ans);
    cout << ans << endl;
    return 0;
}
