#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int x;
    cin >> x;
    for(int i=1; i<n; ++i){
        int y;
        cin >> y;
        x = gcd(x, y);
    }
    int res = 0;
    for(int i=1, y=sqrt(x); i<=y; ++i){
        if(x%i == 0){
            res++;
            if(x/i != i)
                res++;
        }
    }
    cout << res << endl;
    return 0;
}
