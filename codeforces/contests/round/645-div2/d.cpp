#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, x;
    cin >> n >> x;
    vi arr(n), psum1(2*n), psum2(2*n);
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        psum1[i] = arr[i] + (i? psum1[i-1] : 0);
        psum2[i] = (arr[i]*(arr[i]+1))/2 + (i? psum2[i-1] : 0);
    }
    for(int i=n; i<2*n; ++i){
        psum1[i] = arr[i-n] + psum1[i-1];
        psum2[i] = (arr[i-n]*(arr[i-n]+1))/2 + psum2[i-1];
    }
    int ans = 0;
    for(int i=0; i<2*n; ++i){
        if(psum1[i] - x < 0)
            continue;
        int res = psum2[i];
        int l = lower_bound(all(psum1), psum1[i] - x) - psum1.begin();
        res -= psum2[l];
        int diff = psum1[l] - (psum1[i]-x);
        if(diff){
            int di = arr[l%n] - diff + 1;
            res += (diff*(di+arr[l%n]))/2;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
