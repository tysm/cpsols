#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int mesh[n][m];
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                cin >> mesh[i][j];
        }

        int res[n][m];
        for(int i=1; i<n-1; ++i){
            for(int j=1; j<m-1; ++j)
                res[i][j] = INF;
        }
        for(int i=0; i<n; ++i)
            res[i][0] = res[i][m-1] = 0;
        for(int j=0; j<m; ++j)
            res[0][j] = res[n-1][j] = 0;

        for(int k=0; k<100; ++k){
            for(int i=1; i<n-1; ++i){
                for(int j=1; j<m-1; ++j){
                    if(mesh[i-1][j] <= mesh[i][j])
                        res[i][j] = min(res[i][j], res[i-1][j]);
                    else
                        res[i][j] = min(res[i][j], max(res[i-1][j], mesh[i-1][j]));
                    if(mesh[i][j-1] <= mesh[i][j])
                        res[i][j] = min(res[i][j], res[i][j-1]);
                    else
                        res[i][j] = min(res[i][j], max(res[i][j-1], mesh[i][j-1]));
                }
            }
            for(int i=n-2; i>=1; --i){
                for(int j=m-2; j>=1; --j){
                    if(mesh[i+1][j] <= mesh[i][j])
                        res[i][j] = min(res[i][j], res[i+1][j]);
                    else
                        res[i][j] = min(res[i][j], max(res[i+1][j], mesh[i+1][j]));
                    if(mesh[i][j+1] <= mesh[i][j])
                        res[i][j] = min(res[i][j], res[i][j+1]);
                    else
                        res[i][j] = min(res[i][j], max(res[i][j+1], mesh[i][j+1]));
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                ans += max(res[i][j] - mesh[i][j], 0LL);
        }
        cout << ans << endl;
    }
    return 0;
}
