#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    vi pali = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    map<int, int> ipal;
    ipal[2] = 1;
    ipal[3] = 7;
    ipal[4] = 4;
    ipal[5] = 5;
    ipal[6] = 9;
    ipal[7] = 8;
    while(t--){
        int n;
        cin >> n;
        string num;
        cin >> num;
        int pals = 0;
        for(char c:num)
            pals += pali[c-'0'];
        for(int i=0; i<n; ++i){
            int l = (n-i-1)*2, r = (n-i-1)*7;
            for(int d=9; d>=0; --d){
                int aft = pals - pali[d];
                if(aft >= l and aft <= r){
                    pals -= pali[d];
                    cout << d;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
