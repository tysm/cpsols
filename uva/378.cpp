#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(t--){
        point<int> a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        line<int> l(a, b - a), r(c, d - c);
        if(intersect(l, r)){
            auto its = intersection(l, r);
            if(!its.is_degenerate())
                cout << "LINE" << endl;
            else
                cout << "POINT" << ' ' << fixed << setprecision(2) << its.p.x << ' ' << its.p.y << endl;
        }
        else
            cout << "NONE" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
