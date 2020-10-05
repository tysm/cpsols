#include <cpplib/stdinc.hpp>

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string val = "RGB";

        vvi dis(3, vi(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<3; ++j){
                dis[j][i] = (val[(j+i)%3] != s[i]);
                if(i)
                    dis[j][i] += dis[j][i-1];
            }
        }
        int ans = LINF;
        for(int l=-1, r=k-1; r<n; ++l, ++r){
            for(int j=0; j<3; ++j)
                ans = min(ans, dis[j][r] - (l >= 0? dis[j][l] : 0));
        }
        cout << ans << endl;
    }
}
