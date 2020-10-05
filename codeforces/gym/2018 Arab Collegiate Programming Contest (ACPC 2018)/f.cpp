#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>

int32_t main(){
    ifstream cin("fetiera.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        double tot = n*(n+1)*n*(n+1)/4;

        double keep[n][n] = {}, change[n][n] = {};
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                double l = i+1, r = n-i, u = j+1, d = n-j;
                change[i][j] = (l*r*u*d)/tot;
                keep[i][j] = 1 - change[i][j];
            }
        }

        double ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int x;
                cin >> x;

                matrix<double, 2, 1> ini(0);
                ini[1-x][0] = 1;

                matrix<double, 2> c(0);
                c[0][0] = keep[i][j];
                c[1][1] = keep[i][j];
                c[0][1] = change[i][j];
                c[1][0] = change[i][j];

                auto res = exp(c, k);
                ans += (res*ini)[0][0];
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
