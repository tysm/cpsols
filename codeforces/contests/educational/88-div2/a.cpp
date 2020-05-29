#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int each = n/k;
        if(m <= each)
            cout << m << endl;
        else{
            m -= each;
            cout << each - ceil((double)m/(k-1)) << endl;
        }
    }
    return 0;
}
