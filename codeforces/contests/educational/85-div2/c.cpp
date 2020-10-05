#include <cpplib/stdinc.hpp>

int mod(int a, int b){
    return (a%b + b)%b;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n), b(n);
        for(int i=0; i<n; ++i)
            cin >> a[i] >> b[i];
        vi ea(2*n), psum(2*n);
        for(int i=0; i<2*n; ++i){
            ea[i] = max((int)0, a[i%n] - b[mod(i-1, n)]);
            psum[i] = ea[i];
            if(i)
                psum[i] += psum[i-1];
        }
        int ans = LINF;
        for(int i=0; i<n; ++i){
            int cur = a[i] + psum[i+n-1] - psum[i];
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
