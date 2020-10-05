#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        int x5 = max(x1, x3), y5 = max(y1, y3);
        int x6 = min(x2, x4), y6 = min(y2, y4);
        if(x5 >= x6 or y5 >= y6) // no intersection.
            cout << "No Overlap" << endl;
        else
            cout << x5 << ' ' << y5 << ' ' << x6 << ' ' << y6 << endl;
        if(t)
            cout << endl;
    }
    return 0;
}
