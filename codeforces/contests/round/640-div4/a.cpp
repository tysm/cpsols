#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, aux = 1;
        cin >> n;
        vi ans;
        while(n){
            if(n%10)
                ans.pb((n%10)*aux);
            aux *= 10;
            n /= 10;
        }
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
