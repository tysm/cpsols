#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == y and y == z)
            cout << "YES" << endl << x << ' ' << x << ' ' << x << endl;
        else if(x == y){
            if(z < x)
                cout << "YES" << endl << x << ' ' << z << ' ' << z << endl;
            else
                cout << "NO" << endl;
        }
        else if(y == z){
            if(x < y)
                cout << "YES" << endl << x << ' ' << x << ' ' << y << endl;
            else
                cout << "NO" << endl;
        }
        else if(x == z){
            if(y < x)
                cout << "YES" << endl << y << ' ' << x << ' ' << y << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
