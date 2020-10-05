#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n), psum(2e5+2);
    for(int &i:arr){
        cin >> i;
        psum[1]++;
        psum[i+1]--;
    }
    for(int i=1; i<psum.size(); ++i)
        psum[i] += psum[i-1];
    for(int i=1; i<psum.size(); ++i)
        psum[i] += psum[i-1];

    int mi = *min_element(all(arr)), ma = *max_element(all(arr));

    int j = ma, ans = 0;
    for(int i=ma-1; i>mi; --i){
        int sum = psum[j]-psum[i-1];
        if(sum > k){
            ans++;
            j=i;
        }
    }
    if(psum[j]-psum[mi])
        ans++;
    cout << ans << endl;
    return 0;
}
