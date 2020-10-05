#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vii arr;
        for(int i=0; i<n; ++i){
            int a, b, c;
            cin >> a >> b >> c;

            for(int j=1; j<=c; j*=2){
                arr.eb(a*j, b*j);
                c -= j;
            }
            if(c)
                arr.eb(a*c, b*c);
        }

        vi dp(k+1);
        n = arr.size();
        for(int i=0; i<n; ++i){
            int a, b;
            tie(a, b) = arr[i];
            for(int j=k; j>=a; --j)
                dp[j] = max(dp[j], dp[j-a] + b);
        }
        cout << *max_element(all(dp)) << endl;
    }
    return 0;
}
