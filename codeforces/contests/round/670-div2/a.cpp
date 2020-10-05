#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt[102] = {};
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cnt[x]++;
        }
        int a = 0;
        while(cnt[a] > 1)
            a++;
        int b = 0;
        while(cnt[b] > 0)
            b++;
        cout << a+b << endl;
    }
    return 0;
}
