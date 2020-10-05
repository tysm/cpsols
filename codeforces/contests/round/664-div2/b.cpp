#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << x << ' ' << y << endl;
    for(int j=1; j<=m; ++j){
        if(j == y)
            continue;
        cout << x << ' ' << j << endl;
    }
    y = m;
    for(int i=1; i<=n; ++i){
        if(i == x)
            continue;

        bool inc = (y == 1);
        if(inc){
            for(int j=1; j<=m; ++j)
                cout << i << ' ' << j << endl;
            y = m;
        }
        else{
            for(int j=m; j>=1; --j)
                cout << i << ' ' << j << endl;
            y = 1;
        }
    }
    return 0;
}
