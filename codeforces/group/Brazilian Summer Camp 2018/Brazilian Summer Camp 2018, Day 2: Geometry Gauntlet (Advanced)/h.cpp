#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/line.hpp>
#include <cpplib/adt/polygon.hpp>
#include <cpplib/geo/cvhull.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vector<line<double> > arr;
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        arr.eb(make_line2d(a, b, c));
    }

    vector<point<int> > pts(m);
    for(auto &p:pts)
        cin >> p.x >> p.y;

    polygon<int> pl(get<0>(convex_hull(pts)));

    vi ans;
    for(int i=0; i<n; ++i){
        if(intersect(arr[i], pl))
            ans.eb(i+1);
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
