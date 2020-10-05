#include <cpplib/stdinc.hpp>

bool check(vi &arr, vii &cost, int n, int k){
    int sum = 0, i = 0;
    for(auto [c, pos] : cost){
        if(pos < n){
            sum += arr[i++]*(-c);
            if(i == n)
                break;
        }
    }
    return sum >= k;
}

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
            i /= 100;
        }
        sort(rall(arr));

        int x, a, y, b;
        cin >> x >> a >> y >> b;

        vii cost;
        for(int i=1; i<=n; ++i){
            int c = 0;
            if(i%a == 0)
                c += x;
            if(i%b == 0)
                c += y;
            cost.eb(-c, i-1);
        }
        sort(all(cost));

        int k;
        cin >> k;

        int lo = 1, hi = n, ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(check(arr, cost, mid, k)){
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}
