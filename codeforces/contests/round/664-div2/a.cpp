#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int cnt[2] = {};
        cnt[r%2]++;
        cnt[g%2]++;
        cnt[b%2]++;
        if(w%2){
            if(cnt[1] == 3 or cnt[1] == 0)
                cout << "Yes" << endl;
            else if(cnt[1] == 2 and min({r, g, b}) >= 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else{
            if(cnt[1] != 2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
