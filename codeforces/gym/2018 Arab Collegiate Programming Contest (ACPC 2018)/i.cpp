#include <cpplib/stdinc.hpp>

int32_t main(){
    ifstream cin("icecream.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vii arr(n);
        for(int i=0; i<n; ++i)
            cin >> arr[i].ff;
        for(int i=0; i<n; ++i)
            cin >> arr[i].ss;
        sort(all(arr));

        int ans1 = arr[k-1].ff;

        vi res;
        for(ii i:arr){
            if(i.ff <= ans1)
                res.eb(i.ss);
            else
                break;
        }

        int ans2 = 0;
        sort(rall(res));
        for(int i=0; i<k; ++i)
            ans2 += res[i];
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
