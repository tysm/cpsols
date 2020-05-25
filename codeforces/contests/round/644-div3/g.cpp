#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int cntl[n] = {}, cntr[m] = {}, arr[n][m] = {};
        for(int i=0; i<n; ++i){
            int k = mod(i*a - (b-1), m);
            for(int l=0; l<a; ++l){
                int j = (k+l)%m;
                arr[i][j] = 1;
                cntl[i]++;
                cntr[j]++;
            }
        }
        bool valid = true;
        for(int i=0; i<n; ++i)
            valid &= (cntl[i] == a);
        for(int i=0; i<m; ++i)
            valid &= (cntr[i] == b);
        if(valid){
            cout << "YES" << endl;
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j)
                    cout << arr[i][j];
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
