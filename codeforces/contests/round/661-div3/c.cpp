#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi w(n);
        for(int &i:w)
            cin >> i;

        int ans = 0;
        for(int i=2; i<=2*n; ++i){
            vi cnt(2*n+1);
            for(int j:w)
                cnt[j]++;

            int acc = 0;
            for(int j:w){
                if(!cnt[j])
                    continue;
                if(j >= i)
                    continue;

                int c;
                if(j == i-j)
                    c = cnt[j]/2;
                else
                    c = min(cnt[j], cnt[i-j]);

                acc += c;

                cnt[j] -= c;
                cnt[i-j] -= c;
            }
            ans = max(acc, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
