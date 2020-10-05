#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi cnt(2);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        cnt[x]++;
    }

    if(cnt[0] > cnt[1])
        cout << vi(n/2, 0) << endl;
    else
        cout << vi(n/2, 1) << endl;
    return 0;
}
