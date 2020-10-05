#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, d;
    cin >> n >> m >> d;

    set<ii> arr;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        arr.emplace(x, i);
    }

    int res = 0;
    vi ans(n);
    while(!arr.empty()){
        ii cur = *arr.begin();
        arr.erase(arr.begin());

        ans[cur.ss] = res+1;
        while(!arr.empty() and cur.ff+d+1 <= m){
            auto it = arr.lower_bound({cur.ff+d+1, -1});
            if(it == arr.end())
                break;
            cur = *it;
            arr.erase(it);

            ans[cur.ss] = res+1;
        }
        res++;
    }
    cout << res << endl;
    cout << ans << endl;
    return 0;
}
