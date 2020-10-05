#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, x;
    cin >> n >> x;
    vi arr(n);
    set<int> vis;
    int ans = -1;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        if(vis.count(arr[i])){
            ans = 0;
            break;
        }
        else if(vis.count(arr[i] & x))
            ans = 1;
        vis.emplace(arr[i]);
    }
    if(ans == -1){
        vis.clear();
        for(int i=0; i<n; ++i){
            if(vis.count(arr[i])){
                ans = 1;
                break;
            }
            else if(vis.count(arr[i] & x))
                ans = 2;
            vis.emplace(arr[i] & x);
        }
    }
    cout << ans << endl;
    return 0;
}
