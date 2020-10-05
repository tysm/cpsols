#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr)
            cin >> i;
        reverse(all(arr));

        cout << arr << endl;
    }
    return 0;
}
