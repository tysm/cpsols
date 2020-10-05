#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/see.hpp>

int32_t main(){
    int n;
    cin >> n;
    vector<point<int> > points;
    for(int i=0; i<n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        points.eb(x, y, z);
    }
    auto res = get<0>(see(points, 70000));
    cout.precision(10);
    cout << res.x << ' ' << res.y << ' ' << res.z << endl;
}
