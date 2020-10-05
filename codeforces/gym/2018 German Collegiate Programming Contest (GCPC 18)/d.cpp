#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    bool ok = true;

    int l = 0;
    for(int i=0, cur = l; i<n; ++i){
        int x = arr[i] - cur;
        if(x < 0){
            if(i%2 == 0){
                ok = false;
                break;
            }
            l += abs(x);
            cur = 0;
        }
        else
            cur = x;
    }
    if(!ok){
        cout << 0 << endl;
        return 0;
    }

    int r = arr[0];
    for(int i=0, cur = r; i<n; ++i){
        int x = arr[i] - cur;
        if(x < 0){
            if(i%2){
                ok = false;
                break;
            }
            r += x;
            cur = 0;
        }
        else
            cur = x;
    }
    if(!ok){
        cout << 0 << endl;
        return 0;
    }

    cout << max(r-l+1, (int)0) << endl;
    return 0;
}
