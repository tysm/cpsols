#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vi a(n+1), pa(n+1), b(n+1), pb(n+1);
        for(int i=1; i<=n; ++i){
            cin >> a[i];
            pa[i] = a[i] + pa[i-1];
        }
        for(int i=1; i<=n; ++i){
            cin >> b[i];
            pb[i] = b[i] + pb[i-1];
        }

        vi dp(n+1, INF), back(n+1);
        dp[0] = 0;

        for(int i=1, j=0; i<=n; ++i){
            while(j < i){
                int v = min(pa[j], pb[j]);
                if(pa[i] - v < k and pb[i] - v < k)
                    break;
                j++;
            }
            if(j == i)
                continue;
            back[i] = j;
            dp[i] = dp[j] + 1;
        }

        int last = -1, ans = INF;
        for(int i=0, j=0; i<n; ++i){
            while(j < n and pb[j] - min(pa[i], pb[i]) < k)
                j++;
            if(pb[j] - min(pa[i], pb[i]) < k)
                continue;
            if(pa[j] - min(pa[i], pb[i]) >= k)
                continue;
            if(dp[i] < ans){
                ans = dp[i];
                last = i;
            }
        }
        if(ans == INF){
            cout << -1 << endl;
            continue;
        }

        cout << ans << endl;
        vi res;
        while(last > 0){
            res.eb(last);
            last = back[last];
        }
        reverse(all(res));
        cout << res << endl;
    }
    return 0;
}
