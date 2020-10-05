#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        queue<ii> q;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;

            if(x){
                q.ep(i, arr[i]);
                arr[i] = -INF;
            }
        }
        sort(rall(arr));

        vi ans(n);
        for(int i=0, j=0; i<n; ++i){
            if(!q.empty() and q.front().ff == i){
                ans[i] = q.front().ss;
                q.pop();
            }
            else
                ans[i] = arr[j++];
        }
        cout << ans << endl;
    }
    return 0;
}
