#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geometry/see.hpp>

int32_t main(){
    ifstream cin("robots.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, R, r;
        cin >> n >> R >> r;
        vector<point<int> > points;
        point<int> p;
        points.eb(p);
        for(int i=0; i<n; ++i){
            int dx, dy;
            cin >> dx >> dy;
            p.x += dx;
            p.y += dy;
            points.eb(p);
        }
        auto c = get<0>(see(points));
        cout << fixed << setprecision(10) << -c.x << ' ' << -c.y << endl;
    }
    return 0;
}
