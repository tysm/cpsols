#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1632
    desync();
    int n, k;
    cin >> n >> k;
    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;
    sort(arr.begin(), arr.end(), [](const ii i, const ii j){ return tie(i.ss, j.ff) < tie(j.ss, i.ff); });
    multiset<int> last;
    for(int i=0; i<k; ++i)
        last.insert(1);

    int ans = 0;
    for(ii &i:arr){
        auto it = last.lower_bound(-i.ff);
        if(it != last.end()){
            ans++;
            last.erase(it);
            last.insert(-i.ss);
        }
    }
    cout << ans << endl;
    return 0;
}
