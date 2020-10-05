#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>

int32_t main(){
    desync();
    int n;
    double p;
    cin >> n >> p;
    matrix<double, 2> a;
    a[0][0] = 1-p;
    a[0][1] = p;
    a[1][0] = p;
    a[1][1] = 1-p;
    auto res = exp(a, n);
    cout.precision(10);
    cout << fixed << res[0][0] << endl;
    return 0;
}
