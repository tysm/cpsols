#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics/combinatorics.hpp>

int32_t main(){
    ifstream cin("popcorn.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << C(n, k) << endl;
    }
    return 0;
}
