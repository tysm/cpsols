#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int arr[int32_t(1e3)+1][int32_t(1e3)+1] = {};
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }
    int res0 = arr[0][1]/sqrt((arr[0][1]*arr[2][1])/arr[0][2]);
    cout << res0;
    for(int i=1; i<n; ++i){
        cout << ' ' << (arr[i][0]/res0);
    }
    cout << endl;
    return 0;
}
