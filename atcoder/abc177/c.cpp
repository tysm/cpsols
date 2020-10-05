#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    mint sum = 0, ans = 0;
    for(int i=0; i<n; ++i){
        ans += sum*arr[i];
        sum += arr[i];
    }
    cout << ans << endl;
    return 0;
}
