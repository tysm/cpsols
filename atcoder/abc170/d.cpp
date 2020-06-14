#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n), cnt(MAX);
    for(int &i:arr){
        cin >> i;
        cnt[i]++;
    }
    int ans = 0;
    for(int i:arr){
        cnt[i]--;
        bool valid = true;
        for(int j=1; j*j<=i; ++j){
            if(i%j)
                continue;
            if(cnt[j] or cnt[i/j])
                valid = false;
        }
        ans += valid;
        cnt[i]++;
    }
    cout << ans << endl;
    return 0;
}
