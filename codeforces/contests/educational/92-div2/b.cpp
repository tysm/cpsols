#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        int sum = 0, mx = 0, ans = 0;
        for(int i=0; i<=k; ++i){
            if(i < n-1)
                mx = max(mx, arr[i] + arr[i+1]);
            sum += arr[i];
            if(i%2 == k%2){
                int aux = (k-i)/2;
                if(aux <= z)
                    ans = max(ans, sum + mx*aux);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
