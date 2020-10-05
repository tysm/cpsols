#include <cpplib/stdinc.hpp>
#include <cpplib/math/progression.hpp>

int32_t main(){
    desync();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int n = r-l+1;
        if(l%2){
            if(n == 1)
                cout << -l << endl;
            else
                cout << sum_ap(-l, (int)-2, (n+1)/2) + sum_ap(l+1, (int)2, n/2) << endl;
        }
        else{
            if(n == 1)
                cout << l << endl;
            else
                cout << sum_ap(l, (int)2, (n+1)/2) + sum_ap(-(l+1), (int)-2, n/2) << endl;
        }
    }
    return 0;
}
