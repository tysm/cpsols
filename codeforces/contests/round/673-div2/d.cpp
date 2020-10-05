#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int sum = 0;
        vi arr(n);
        for(int &i:arr){
            cin >> i;
            sum += i;
        }
        if(sum%n){
            cout << -1 << endl;
            continue;
        }
        int val = sum/n;


        vtt ans;
        vii mods;
        for(int j=2; j<=n; ++j){
            if(arr[j-1]%j){
                int x = j - arr[j-1]%j;
                arr[0] -= x;
                arr[j-1] += x;
                ans.eb(1, j, x);
            }
            int x = arr[j-1]/j;
            arr[j-1] = 0;
            arr[0] += x*j;
            ans.eb(j, 1, x);
        }
        for(int j=2; j<=n; ++j)
            ans.eb(1, j, val);

        cout << ans.size() << endl;
        for(auto [i, j, x]:ans)
            cout << i << ' ' << j << ' ' << x << endl;
    }
    return 0;
}
