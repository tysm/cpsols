#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

bool inside(point<int> sq[4], point<int> p){
    map<int, int> cnt;
    for(int i=0; i<4; ++i){
        int j = (i+1)%4;
        int cw = get<2>(orientation(sq[i]-p, sq[j]-p));
        cnt[cw]++;
    }
    return cnt[1] and !cnt[-1] or cnt[-1] and !cnt[1];
}

int32_t main(){
    desync();
    point<int> a[4], b[4];

    for(int i=0; i<4; ++i)
        cin >> a[i].x >> a[i].y;
    for(int i=0; i<4; ++i)
        cin >> b[i].x >> b[i].y;

    bool ans = false;
    for(int i=0; i<4; ++i){
        int j = (i+1)%4;
        segment<int> sa(a[i], a[j]);
        for(int k=0; k<4; ++k){
            int l=(k+1)%4;
            segment<int> sb(b[k], b[l]);
            ans |= intersect(sa, sb);
        }
        ans |= inside(a, b[i]);
        ans |= inside(b, a[i]);
    }
    cout << (ans? "YES":"NO") << endl;
    return 0;
}
