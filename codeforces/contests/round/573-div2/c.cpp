#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    vi arr(m);
    for(int &i:arr){
        cin >> i;
        i--;
    }

    int i = 0, j = 0, acc = 0, ans = 0;
    while(i < m){
        ans++;

        int l = ((arr[i]+acc)/k)*k, r = l+k-1;
        while(j < m and arr[j]+acc <= r)
            j++;

        acc -= j-i;
        i = j;
    }
    cout << ans << endl;
    return 0;
}
