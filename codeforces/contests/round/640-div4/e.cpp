#include <cpplib/stdinc.hpp>

bool solve(vi &arr, int v){
    int acc = arr[0], i = 0, j = 0;
    while(j < arr.size()){
        if(acc < v or i == j){
            j++;
            if(j < arr.size())
                acc += arr[j];
        }
        else if(acc > v)
            acc -= arr[i++];
        if(acc == v and j-i >= 1 and j < arr.size())
            return true;
    }
    return false;
}

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

        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += solve(arr, arr[i]);
        cout << ans << endl;
    }
    return 0;
}
