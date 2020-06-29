#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ocnt = 0, cend = 0;
        for(int i=0; i<n; ++i){
            char c;
            cin >> c;
            if(c == ')'){
                if(!ocnt)
                    cend++;
                else
                    ocnt--;
            }
            else
                ocnt++;
        }
        cout << min(ocnt, cend) << endl;
    }
    return 0;
}
