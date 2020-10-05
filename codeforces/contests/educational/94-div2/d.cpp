#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr){
            cin >> i;
            i--;
        }

        int ans = 0;
        for(int i=0; i+2<n; ++i){
            vi cntj(n), cntl(n);

            for(int j=i+2; j<n; ++j)
                cntl[arr[j]]++;

            int cur = 0;
            for(int k=i+2; k<n; ++k){
                cur -= cntl[arr[k-1]]*cntj[arr[k-1]];
                cntj[arr[k-1]]++;
                cur += cntl[arr[k-1]]*cntj[arr[k-1]];

                cur -= cntl[arr[k]]*cntj[arr[k]];
                cntl[arr[k]]--;
                cur += cntl[arr[k]]*cntj[arr[k]];
                if(arr[i] == arr[k])
                    ans += cur;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
