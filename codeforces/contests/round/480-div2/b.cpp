#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    char ans[4][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j)
            ans[j][i] = '.';
    }
    int i = 1;
    while(k > 1 and i <= 2){
        for(int j=1; j<n/2 and k>1; ++j){
            ans[i][j] = ans[i][n-j-1] = '#';
            k -= 2;
        }
        i++;
    }
    for(i=1; i<=2 and k>0; ++i, k--)
        ans[i][n/2] = '#';
    cout << "YES" << endl;
    for(int i=0; i<4; ++i){
        for(int j=0; j<n; ++j)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
