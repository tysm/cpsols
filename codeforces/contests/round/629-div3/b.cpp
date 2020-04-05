#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int acc = 0;
        string s(n, 'a');
        for(int i=1; i<n; ++i){
            acc += i;
            if(k <= acc){
                s[n-1-i] = 'b';
                s[n-i+(acc-k)] = 'b';
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}
