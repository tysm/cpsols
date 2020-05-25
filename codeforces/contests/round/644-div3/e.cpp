#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vvi arr(n, vi(n));
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            for(int j=0; j<n; ++j)
                arr[i][j] = s[j]-'0';
        }
        vvi dp(n, vi(n));
        for(int i=0; i<n; ++i){
            for(int j=n-1, aux=1; j>=0; --j){
                dp[i][j] += aux;
                aux = arr[i][j];
            }
            for(int j=n-1, aux=1; j>=0; --j){
                dp[j][i] += aux;
                aux = arr[j][i];
            }
        }
        bool valid = true;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(arr[i][j] and !dp[i][j])
                    valid = false;
            }
        }
        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
