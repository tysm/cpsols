#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));
    cout << arr[n/2 - (n%2 == 0)] << endl;
    return 0;
}
