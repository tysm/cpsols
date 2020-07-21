#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    point<int> p;
    segment<int> s;
    cin >> p.x >> p.y >> s.a.x >> s.a.y >> s.b.x >> s.b.y;
    cout << (count(s, p)? "YES" : "NO") << endl;
    return 0;
}
