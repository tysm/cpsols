#include <cpplib/stdinc.hpp>
#include <cpplib/adt/geoinc.hpp>

#undef debug
#define debug(x) // debug(x)

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        double z;
        cin >> n >> m >> z;

        vector<point<int> > arr(n);
        for(auto &i:arr)
            cin >> i.x >> i.y;

        int ans = 0;

        double z2 = (double)z/2;
        for(auto i:arr){
            debug(i);
            point<int> v = -i;

            double d = norm(v);
            double l = sqrt(d*d - z2*z2);
            debug(l);

            double ang = asin(z2/d);

            point<double> iz1 = rotate(point<double>(v), point<int>(0, 0, 1), abs(ang));
            iz1 = iz1.as_unit();
            debug(norm(iz1));

            auto zp1 = iz1*l + i;
            debug(zp1);
            debug(norm(zp1));

            point<double> iz2 = rotate(point<double>(v), point<int>(0, 0, 1), -abs(ang));
            iz2 = iz2.as_unit();
            debug(norm(iz2));

            auto zp2 = iz2*l + i;
            debug(zp2);
            debug(norm(zp2));

            double atr1 = angle(point<int>(1, 0), point<double>(0, 0), zp1);
            double atr2 = angle(zp2, point<double>(0, 0), point<int>(1, 0));

            int res1 = 0, res2 = 0;
            for(auto j:arr){
                auto pj1 = rotate(point<double>(j), point<double>(0, 0, 1), atr1);
                debug(pj1);
                if(abs(pj1.x) < z2+EPS and pj1.y + EPS > 0)
                    res1++;

                auto pj2 = rotate(point<double>(j), point<double>(0, 0, 1), atr2);
                debug(pj2);
                if(abs(pj2.x) < z2+EPS and pj2.y + EPS > 0)
                    res2++;
            }
            ans = max({ans, res1, res2});
        }
        cout << (ans >= m? "Yes" : "No") << endl;
    }
    return 0;
}
