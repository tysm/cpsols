#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    set<int> dp;
    int sum = 0, ans = 0;
    for(int i=0; i<n; ++i){
        dp.ep(sum);
        sum += arr[i];
        if(dp.count(sum)){
            ans++;

            dp.clear();
            dp.ep(0);
            sum = arr[i];
        }
    }

    cout << ans << endl;
    return 0;
}
