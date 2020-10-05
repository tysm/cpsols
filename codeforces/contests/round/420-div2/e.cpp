#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

#define tt tuple<int, int, int>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vector<tt> arr;
    for(int i=0; i<n; ++i){
        int x1, x2, c;
        cin >> x1 >> x2 >> c;
        arr.eb(x1, x2, c);
    }

    matrix<mint, 16, 1> cur(0);
    cur[0][0] = 1;
    for(int i=0; i<n; ++i){
        int x1, x2, c;
        tie(x1, x2, c) = arr[i];

        matrix<mint, 16> op(0);
        for(int j=0; j<=c; ++j){
            op[j][j] = 1;
            if(j)
                op[j][j-1] = 1;
            if(j < c) 
                op[j][j+1] = 1;
        }

        int d = x2-x1;
        if(x2 >= k)
            d = k-x1;

        cur = exp(op, d)*cur;

        if(x2 >= k)
            break;
    }
    cout << cur[0][0] << endl;
    return 0;
}
