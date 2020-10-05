#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi d(n+1, -1), lst(n+1, -1);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(lst[x] == -1)
                d[x] = i;
            else
                d[x] = max(d[x], i-1-lst[x]);
            lst[x] = i;
        }
        for(int i=1; i<=n; ++i){
            if(lst[i] == -1)
                continue;
            d[i] = max(d[i], n-1-lst[i]);
        }
        vi ans;
        int i=1;
        for(int k=n; k>=1; --k){
            while(i <= n and (lst[i] == -1 or d[i] >= k))
                i++;
            if(i > n)
                ans.eb(-1);
            else
                ans.eb(i);
        }
        reverse(all(ans));
        cout << ans << endl;
    }
    return 0;
}
