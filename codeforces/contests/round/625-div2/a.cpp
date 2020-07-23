#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arra(n), arrb(n);
    for(int &i:arra)
        cin >> i;
    for(int &i:arrb)
        cin >> i;
    int a = 0, b = 0;
    for(int i=0; i<n; ++i){
        if(arra[i] and !arrb[i])
            a++;
        if(!arra[i] and arrb[i])
            b++;
    }
    if(a == 0)
        cout << -1 << endl;
    else if(a > b)
        cout << 1 << endl;
    else
        cout << (b+1)/a + ((b+1)%a != 0) << endl;
    return 0;
}
