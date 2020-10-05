#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        matrix<modular<(int)1e9>, 10, 1> base(0);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            base[i][0] = x;
        }

        matrix<modular<(int)1e9>, 10> c(0);
        for(int i=n-1; i>=0; --i){
            int x;
            cin >> x;
            c[n-1][i] = x;
        }
        for(int i=0; i<n-1; ++i)
            c[i][i+1] = 1;

        int k;
        cin >> k;
        cout << (exp(c, k-1)*base)[0][0] << endl;
    }
    return 0;
}
