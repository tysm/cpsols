#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int x, n;
    cin >> x >> n;
    vb cnt(1e2+2);
    for(int i=0; i<n; ++i){
        int p;
        cin >> p;
        cnt[p] = true;
    }
    int ans = -1;
    for(int i=x; i<=101 and ans==-1; ++i){
        if(!cnt[i])
            ans = i;
    }
    for(int j=x; j>=0 and abs(x-j) <= abs(x-ans); --j){
        if(!cnt[j])
            ans = j;
    }
    cout << ans << endl;
    return 0;
}
