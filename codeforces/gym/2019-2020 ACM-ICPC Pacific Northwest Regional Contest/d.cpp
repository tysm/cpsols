#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while(a > b){
        if(a%2){
            a++;
            ans++;
        }
        a >>= 1;
        ans++;
    }
    cout << b-a + ans << endl;
    return 0;
}

