#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

mint solve(int n){
    n++;
    if(n <= 2)
        return 0;

    matrix<mint, 5> f(0);
    f[0][1] = f[1][2] = f[2][3] = 1;
    f[3][3] = f[3][2] = f[3][1] = f[3][0] = 1;
    f[4][4] = f[4][3] = 1;

    f = exp(f, n-3);

    matrix<mint, 5, 1> ini(0);
    ini[3][0] = 1;
    return (f*ini)[4][0];
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        cout << solve(n) - solve(m-1) << endl;
    }
    return 0;
}
