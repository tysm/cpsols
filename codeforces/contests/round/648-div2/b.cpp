#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arra(n), arrb(n);
        for(int &i:arra)
            cin >> i;
        int cnt0 = 0, cnt1 = 0;
        for(int &i:arrb){
            cin >> i;
            if(i)
                cnt1++;
            else
                cnt0++;
        }
        bool valid = true;
        if(cnt0 == 0 or cnt1 == 0){
            for(int i=1; i<n; ++i){
                if(arra[i] < arra[i-1])
                    valid = false;
            }
        }
        if(valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
