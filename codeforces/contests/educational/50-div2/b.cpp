#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int q;
    cin >> q;
    while(q--){
        int n, m, k;
        cin >> n >> m >> k;
        if(n < m)
            swap(n, m);
        if(n%2 != m%2){
            n--;
            k--;
        }
        else if(n%2 != k%2){
            n--;
            m--;
            k -= 2;
        }
        cout << (k < n? -1 : k) << endl;
    }
    return 0;
}
