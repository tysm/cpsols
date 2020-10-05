#include <cpplib/stdinc.hpp>

// a b
// c d
// x*a + (1-x)*b >= x*c + (1-x)*d
// x*(a-c) + (1-x)*(b-d) >= 0
// x*(a-c) + (b-d) + x*(d-b) >= 0
// x*(a-c + d-b) >= (d-b)
// x*u >= v

int32_t main(){
    desync();
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    if(a < b)
        swap(a, b);

    double l = 0, r = 1;
    for(int i=1; i<n; ++i){
        int c, d;
        cin >> c >> d;
        if(c < d)
            swap(c, d);

        double u = (a - c - b + d), v = (d - b), x = v/u;
        if(abs(u) < EPS){
            if(v >= EPS){
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(u >= EPS)
            l = max(l, x);
        else
            r = min(r, x);

        a = c;
        b = d;
    }
    cout << (l - r >= EPS?  "NO" : "YES") << endl;
    return 0;
}
