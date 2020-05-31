#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int o = 0, e = 0;
        for(int i=0; i<n; ++i){
            int v;
            cin >> v;
            o += v%2;
            e += (v%2 == 0);
        }
        bool valid = false;
        for(int i=1; i<=x and i<=o; i+=2){
            if(i+e>=x)
                valid = true;
        }
        if(valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
