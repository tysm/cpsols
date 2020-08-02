#include <cpplib/stdinc.hpp>

int solve(vi &cnt, int i){
    int ans = 0;
    for(int j=cnt.size()-1; i < j; ++i, --j)
        ans = max(ans, cnt[i]+cnt[j]);
    return ans;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi cnt(m);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        cnt[x-1]++;
    }
    sort(rall(cnt));
    int i=0, ans = cnt[0]*m;
    if(m & 1)
        i++;
    for(; i<m; i+=2)
        ans = min(ans, (i+(m-i)/2)*max(cnt[0], solve(cnt, i)));
    cout << ans << endl;
    return 0;
}
