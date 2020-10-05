#include <cpplib/stdinc.hpp>
#include <cpplib/adt/circle.hpp>
#include <cpplib/geo/see.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<point<int> > arr(n);
    for(auto &p:arr)
        cin >> p.x >> p.y;

    auto c = see(arr);
    cout << fixed << setprecision(16);
    cout << c.c.x << ' ' << c.c.y << endl;
    cout << c.r << endl;
    return 0;
}
