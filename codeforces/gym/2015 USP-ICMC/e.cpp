#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));
    cout << arr[m-1] << endl;
    return 0;
}
