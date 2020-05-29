#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    int n, l, r;
    cin >> n >> l >> r;
    int mini = 0, maxi = 0;
    int aux = bexp(2, r-1);
    maxi += aux*(n-r);
    for(int i = r-1; i>=0; --i){
        maxi += aux;
        aux/=2;
    }
    aux = bexp(2, l-1);
    mini += 1*(n-l);
    for(int i = l-1; i>=0; --i){
        mini += aux;
        aux/=2;
    }
    cout << mini << ' ' << maxi << endl;
    return 0;
}
