#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, l;
    cin >> n >> l;
    vector<map<int, int> > dp(1e5+1);
    dp[0][0] = -1;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        dp[x][y] = -LINF;
    }
    dp[l][0] = 0;
    for(int x=0; x<l; ++x){
        for(ii p:dp[x]){
            int y = p.ff, c = p.ss;
            for(int i=1; i<=5 and x+i<=l; ++i){
                for(int j=-5; j<=5; ++j){
                    if(i + abs(j) > 5)
                        continue;
                    if(!dp[x+i].count(y+j))
                        continue;
                    dp[x+i][y+j] = max(dp[x+i][y+j], c+1);
                }
            }
        }
    }
    cout << dp[l][0] << endl;
    return 0;
}
