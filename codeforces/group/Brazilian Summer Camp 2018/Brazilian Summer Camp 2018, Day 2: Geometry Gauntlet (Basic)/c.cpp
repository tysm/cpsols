#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

int32_t main(){
    desync();
    point<int> arr[4];
    for(int i=0; i<4; ++i)
        cin >> arr[i].x >> arr[i].y;

    segment<int> ab(arr[0], arr[1]), cd(arr[2], arr[3]);
    if(intersect(ab, cd)){
        auto res = intersection(ab, cd);
        cout << fixed << setprecision(10);
        if(res.b < res.a)
            swap(res.b, res.a);
        cout << res.a.x << ' ' << res.a.y;
        if(res.b != res.a)
            cout << endl << res.b.x << ' ' << res.b.y;
    }
    else
        cout << "Empty";
    cout << endl;
    return 0;
}
