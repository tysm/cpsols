#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string x;
        cin >> x;
        string a, b;
        bool amax = false;
        for(int ci:x){
            ci -= '0';
            if(ci == 0){
                a += '0';
                b += '0';
            }
            else if(ci == 1){
                if(amax){
                    a += '0';
                    b += '1';
                }
                else{
                    a += '1';
                    b += '0';
                    amax = true;
                }
            }
            else{
                if(amax){
                    a += '0';
                    b += '2';
                }
                else{
                    a += '1';
                    b += '1';
                }
            }
        }
        cout << a << endl << b << endl;
    }
    return 0;
}
