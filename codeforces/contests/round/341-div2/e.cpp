#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, b, k, x;
    cin >> n >> b >> k >> x;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    matrix<mint, 100, 1> base(0);
    for(int i:arr)
        base[i%x][0] += 1;

    matrix<mint, 100> cf(0);
    for(int i:arr){
        for(int j=0; j<x; ++j)
            cf[(j*10 + i)%x][j] += 1;
    }

    cout << (exp(cf, b-1)*base)[k][0] << endl;
    return 0;
}
