#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<2*k; ++i){
        int a, b;
        cin >> a >> b;
    }
    cout << n-1 + m-1 + n*(m-1) + n-1 << endl;
    for(int i=1; i<n; ++i)
        cout << 'U';
    for(int i=1; i<m; ++i)
        cout << 'L';
    for(int i=0; i<n; ++i){
        for(int j=1; j<m; ++j)
            cout << (i%2? 'L' : 'R');
        if(i != n-1)
            cout << 'D';
    }
    cout << endl;
    return 0;
}
