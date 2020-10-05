#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        vi arr(3);
        for(int &i:arr)
            cin >> i;
        sort(all(arr));

        if(arr[0] + 2*arr[1] <= arr[2])
            cout << arr[2] - (arr[0] + arr[1]) + 1 << endl;
        else
            cout << arr[1] << endl;
    }
    return 0;
}
