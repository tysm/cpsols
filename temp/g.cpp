#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = -1;
    vi res(n+1), pxor(n+1);
    for(int i=3; i<=n; ++i){
        set<int> cnt;
        for(int j=2; j*(j+1)/2 <= i; ++j){
            int sum = j*(j+1)/2, r = i-sum;
            if(r%j)
                continue;
            int val = pxor[r/j + j] ^ pxor[r/j];
            cnt.insert(val);
            if(!val and i == n and ans == -1)
                ans = j;
        }
        int mex = 0;
        while(cnt.count(mex))
            mex++;
        res[i] = mex;
        pxor[i] = pxor[i-1] ^ res[i];
    }
    cout << ans << endl;
    return 0;
}
