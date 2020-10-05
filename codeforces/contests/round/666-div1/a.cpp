#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    if(n == 1){
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << -arr[0] << endl;
    }
    else{
        cout << "1 1" << endl;
        cout << -arr[0] << endl;
        cout << "1 " << n << endl;
        cout << 0;
        for(int i=1; i<n; ++i)
            cout << ' ' << -n*arr[i];
        cout << endl;
        cout << "2 " << n << endl;
        for(int i=1; i<n; ++i)
            cout << (n-1)*arr[i] << " \n"[i == n-1];
    }
    return 0;
}
