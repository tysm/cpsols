#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    for(int i=0; i<5; ++i){
        int x;
        cin >> x;
        if(x != i+1)
            cout << i+1 << endl;
    }
    return 0;
}
