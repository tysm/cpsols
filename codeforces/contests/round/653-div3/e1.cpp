#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vi arr, al, bo;
    for(int i=0; i<n; ++i){
        int t, a, b;
        cin >> t >> a >> b;
        if(a and b)
            arr.pb(t);
        else if(a)
            al.pb(t);
        else if(b)
            bo.pb(t);
    }
    sort(all(arr));
    for(int i=1; i<arr.size(); ++i)
        arr[i] += arr[i-1];
    sort(all(al));
    for(int i=1; i<al.size(); ++i)
        al[i] += al[i-1];
    sort(all(bo));
    for(int i=1; i<bo.size(); ++i)
        bo[i] += bo[i-1];
    int ans = 2*INF;
    for(int i=min(k, (int)arr.size()); i>=0; --i){
        int j = k-i;
        if(al.size() < j or bo.size() < j)
            continue;
        int acc = 0;
        if(i)
            acc += arr[i-1];
        if(j)
            acc += al[j-1] + bo[j-1];
        ans = min(ans, acc);
    }
    cout << (ans == 2*INF? -1 : ans) << endl;
    return 0;
}
