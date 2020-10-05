#include <cpplib/stdinc.hpp>

bool check(int a, int b, int c){
    return a+b>c and a+c>b and b+c>a;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vii arr(n);
        for(int i=0; i<n; ++i){
            cin >> arr[i].ff;
            arr[i].ss = i+1;
        }
        sort(all(arr));
        if(check(arr[0].ff, arr[1].ff, arr[n-1].ff))
            cout << -1 << endl;
        else
            cout << arr[0].ss << ' ' << arr[1].ss << ' ' << arr[n-1].ss << endl;
    }
    return 0;
}
