#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k = 5;
        cin >> n;

        vi ge0, l0;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(x >= 0)
                ge0.eb(x);
            else
                l0.eb(x);
        }
        sort(rall(ge0));
        sort(all(l0));
        n = ge0.size();
        int m = l0.size();

        int ans = -LINF;
        for(int i=0; i<=min(k, n); ++i){
            int ne = k-i;
            if(ne > l0.size())
                continue;
            int res = 1;
            for(int j=0; j<i; ++j){
                if(ne & 1)
                    res *= ge0[n-1-j];
                else
                    res *= ge0[j];
            }
            for(int j=0; j<ne; ++j){
                if(ne & 1)
                    res *= l0[m-1-j];
                else
                    res *= l0[j];
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}
