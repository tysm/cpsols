#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/euclid.hpp>
#include <cpplib/data-structure/geometry/point.hpp>

point<int> normalize(point<int> p){
    if(p.x == 0)
        return {0, 1};
    if(p.y == 0)
        return {1, 0};
    int g = gcd(abs(p.x), abs(p.y));
    p /= g;
    if(p.y < 0)
        return -p;
    return p;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    map<point<int>, int> cnt;
    for(int i=0; i<n; ++i){
        point<int> p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        cnt[normalize(q - p)]++;
    }
    int ans = 0;
    map<point<int>, bool> added;
    for(auto i:cnt){
        auto aux = normalize(point<int>(i.ff.y, -i.ff.x));
        if(i.ss > cnt[aux] or (i.ss == cnt[aux] and !added[aux])){
            ans += i.ss;
            added[i.ff] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
