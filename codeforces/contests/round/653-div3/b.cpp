#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        while(n != 1 and n%3 == 0){
            if(n%2 == 0){
                n /= 6;
                ans++;
            }
            else{
                n /= 3;
                ans += 2;
            }
        }
        cout << (n == 1? ans : -1) << endl;
    }
    return 0;
}
