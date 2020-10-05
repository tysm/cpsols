#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k > n)
            cout << k-n << endl;
        else{
            if(k%2){
                if(n%2 == 0)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
            else{
                if(n%2 == 0)
                    cout << 0 << endl;
                else
                    cout << 1 << endl;
            }
        }
    }
    return 0;
}
