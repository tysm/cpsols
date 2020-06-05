#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, x, y;
    cin >> n >> x >> y;
    vi arr(n);
    for(int &i:arr)
        cin >> i;

    for(int i=0; i<n; ++i){
        bool valid = true;
        for(int j=max((int)0, i-x); j<i; ++j){
            if(arr[i] > arr[j])
                valid = false;
        }
        for(int j=min(n-1, i+y); j>i; --j){
            if(arr[i] > arr[j])
                valid = false;
        }
        if(valid){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
