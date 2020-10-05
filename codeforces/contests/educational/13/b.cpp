#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int y;
    cin >> y;
    int d = 0, n = (y%400 == 0 or y%4 == 0 and y%100 != 0), m;
    for(int i=1; i<y; ++i)
        d += 365 + (i%400 == 0 or i%4 == 0 and i%100 != 0);
    m = d%7;
    for(int i=y; i<=1e6; ++i){
        d += 365 + (i%400 == 0 or i%4 == 0 and i%100 != 0);
        int j = i+1;
        if(d%7 == m and (j%400 == 0 or j%4 == 0 and j%100 != 0) == n){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
