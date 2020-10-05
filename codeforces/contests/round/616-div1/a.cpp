#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m-1);

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        vi mval;
        for(int i=0; i<m; ++i)
            mval.eb(max(arr[i], arr[i+n-m]));

        int nc = m-k-1, ans = 0;
        deque<int> q;
        for(int i=0, j=0; i <= k; ++i){
            while(!q.empty() and q.front() < i)
                q.pop_front();
            while(j < i + nc + 1){
                while(!q.empty() and mval[q.back()] >= mval[j])
                    q.pop_back();
                q.eb(j++);
            }
            ans = max(ans, mval[q.front()]);
        }
        cout << ans << endl;
    }
    return 0;
}
