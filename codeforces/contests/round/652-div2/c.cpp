#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        sort(rall(arr));
        vi fri(k);
        for(int &i:fri)
            cin >> i;
        sort(all(fri));
        int ans = 0;
        for(int i=0; i<k; ++i){
            ans += arr[i];
            if(fri[i] == 1)
                ans += arr[i];
            fri[i]--;
        }
        for(int i=k, j=0; i<n and j<k; ++j){
            if(!fri[j])
                continue;
            ans += arr[i + fri[j] - 1];
            i += fri[j];
        }
        cout << ans << endl;
    }
    return 0;
}
