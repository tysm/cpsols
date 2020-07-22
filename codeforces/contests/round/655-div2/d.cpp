#include <cpplib/stdinc.hpp>

int mod(int x, int m){ return (x%m + m)%m; }

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int i=0; i<n; ++i){
        if(i%2 == 0)
            cin >> arr[i/2];
        else
            cin >> arr[n/2+1+i/2];
    }
    int acc = 0, ans = 0;
    for(int i=0; i<2*n; ++i){
        acc += arr[i%n];
        if(i >= (n+1)/2)
            acc -= arr[mod(i-(n+1)/2, n)];
        ans = max(ans, acc);
    }
    cout << ans << endl;
    return 0;
}
