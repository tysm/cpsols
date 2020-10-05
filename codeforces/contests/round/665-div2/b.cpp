#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        int x2, y2, z2;
        cin >> x2 >> y2 >> z2;

        int ans = 0;

        if(z1 >= y2){
            ans += y2*2;
            z1 -= y2;
            y2 = 0;
            if(z1 >= z2){
                z1 -= z2;
                z2 = 0;
                if(z1 >= x2){
                    z1 -= x2;
                    x2 = 0;
                }
                else{
                    x2 -= z1;
                    z1 = 0;
                }
            }
            else{
                z2 -= z1;
                z1 = 0;
            }
        }
        else{
            ans += z1*2;
            y2 -= z1;
            z1 = 0;
        }

        if(x1 < z2){
            z2 -= x1;
            ans -= 2*z2;
        }
        cout << ans << endl;
    }
    return 0;
}
