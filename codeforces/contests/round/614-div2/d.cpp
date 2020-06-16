#include <cpplib/stdinc.hpp>

int distance(int x0, int y0, int x1, int y1){
    return abs(x1 - x0) + abs(y1 - y0);
}

int distance(ii i, ii j){
    return distance(i.ff, i.ss, j.ff, j.ss);
}

int32_t main(){
    desync();
    int x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vii p;
    while(x0 < 2e16+1 and y0 < 2e16+1){
        if(distance(x0, y0, xs, ys) <= t)
            p.pb({x0, y0});
        x0 = x0*ax + bx;
        y0 = y0*ay + by;
    }
    int n = p.size();
    vvi d(n, vi(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            d[i][j] = distance(p[i], p[j]);
    }
    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            int dis = min(distance({xs, ys}, p[i]), distance({xs, ys}, p[j])) + d[i][j];
            if(dis <= t)
                ans = max(ans, j-i+1);
        }
    }
    cout << ans << endl;
    return 0;
}
