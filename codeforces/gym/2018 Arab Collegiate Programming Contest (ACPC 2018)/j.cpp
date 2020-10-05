#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

int32_t main(){
    ifstream cin("jupiter.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        point<double> N, A, H;
        double L;
        cin >> N.x >> N.y >> N.z;
        cin >> A.x >> A.y >> A.z;
        cin >> L;
        cin >> H.z;
        H.z = -H.z;

        point<double> B = rotate(A, N.as_unit(), 2*PI/3);
        point<double> C = rotate(A, N.as_unit(), -2*PI/3);

        cout << fixed << setprecision(6) << distance(A, H) << ' ' << distance(B, H) << ' ' << distance(C, H) << endl;
    }
    return 0;
}
