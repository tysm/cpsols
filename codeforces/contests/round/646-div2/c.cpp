#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        for(int i=1; i<n; ++i){
            int a, b;
            cin >> a >> b;
            if(a == x or b == x)
                cnt++;
        }
        if(cnt <= 1)
            cout << "Ayush" << endl;
        else{
            int till = n-2;
            if(till%2)
                cout << "Ashish" << endl;
            else
                cout << "Ayush" << endl;
        }
    }
    return 0;
}
