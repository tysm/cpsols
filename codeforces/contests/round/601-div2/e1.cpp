#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x)
            arr.pb(i);
    }
    n = arr.size();
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    int ans = INF*INF;
    for(int k=2; k*k<=n; ++k){
        if(n%k)
            continue;
        int acc = 0;
        for(int i=0; i<n; i+=k){
            int median = arr[i + k/2];
            for(int j=i; j<i+k; ++j)
                acc += abs(arr[j]-median);
        }
        ans = min(ans, acc);

        int ik = n/k;
        acc = 0;
        for(int i=0; i<n; i+=ik){
            int median = arr[i + ik/2];
            for(int j=i; j<i+ik; ++j)
                acc += abs(arr[j]-median);
        }
        ans = min(ans, acc);
    }
    int acc = 0, median = arr[n/2];
    for(int i:arr)
        acc += abs(i-median);
    cout << min(ans, acc) << endl;
    return 0;
}
