#include <cpplib/stdinc.hpp>

bool black(int i, int j){
    return (i+j)%2;
}

int get_black(int x1, int y1, int x2, int y2){
    int col1 = (x2-x1+1+black(x1, y1))/2, col2 = (x2-x1+1+!black(x1, y1))/2;
    return col1*((y2-y1+2)/2) + col2*((y2-y1+1)/2);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int b = get_black(1, 1, n, m);
        int w = n*m - b;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int bi = get_black(x1, y1, x2, y2);
        b -= bi;
        w += bi;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        int wi = (x4-x3+1)*(y4-y3+1) - get_black(x3, y3, x4, y4);
        w -= wi;
        b += wi;

        int ix1 = max(x1, x3), iy1 = max(y1, y3);
        int ix2 = min(x2, x4), iy2 = min(y2, y4);
        if(ix1 <= ix2 and iy1 <= iy2){
            int aux = get_black(ix1, iy1, ix2, iy2);
            w -= aux;
            b += aux;
        }

        cout << w << ' ' << b << endl;
    }
    return 0;
}
