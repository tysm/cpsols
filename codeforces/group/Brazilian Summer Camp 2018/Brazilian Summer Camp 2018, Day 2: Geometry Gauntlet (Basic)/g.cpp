#include <cpplib/stdinc.hpp>
#define double long double
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/cvhull.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<point<int> > arr(n);
    map<point<int>, int> pos;

    for(int i=0; i<n; ++i){
        cin >> arr[i].x >> arr[i].y;
        pos[arr[i]] = i+1;
    }

    auto res = get<0>(convex_hull(arr));
    point<int> area;
    double per = 0;
    cout << res.size() << endl;
    for(int i=0; i<res.size(); ++i){
        cout << pos[res[i]] << " \n"[i == res.size()-1];
        int j = (i+1)%res.size();
        per += distance(res[i], res[j]);
        area += res[i]^res[j];
    }
    cout << fixed << setprecision(16);
    cout << per << endl;
    cout << norm(point<double>(area)/2) << endl;
    return 0;
}
