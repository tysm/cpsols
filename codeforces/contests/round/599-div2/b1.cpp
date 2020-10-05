#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >> n >> a >> b;
        bool ok = true, done = false;
        for(int i=0; i<n; ++i){
            if(a[i] != b[i]){
                if(done){
                    ok = false;
                    break;
                }
                bool found = false;
                for(int j=i+1; j<n; ++j){
                    if(a[i] == a[j] and b[i] == b[j]){
                        swap(a[j], b[i]);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ok = false;
                    break;
                }
                done = true;
            }
        }
        cout << (ok? "Yes" : "No") << endl;
    }
    return 0;
}
