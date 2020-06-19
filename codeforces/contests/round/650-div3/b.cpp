#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int e = 0, o = 0;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(i%2 and x%2 == 0)
                e++;
            if(i%2 == 0 and x%2)
                o++;
        }
        if(e != o)
            cout << -1 << endl;
        else
            cout << e << endl;
    }
    return 0;
}
