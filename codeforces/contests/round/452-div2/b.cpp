#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    bool valid = false;
    vi year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=0; i<12; ++i){
        bool ok = true;
        int fev29 = 0;
        for(int j=0; j<n; ++j){
            int k = (i + j)%12;
            if(k == 1){
                if(arr[j] == 29)
                    fev29++;
                else if(arr[j] != year[k])
                    ok = false;
            }
            else if(arr[j] != year[k])
                ok = false;
        }
        if(ok and fev29 <= 1)
            valid = true;
    }
    if(valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
