#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1081
    desync();

    int n;
    cin >> n;

    vi freq(1e6+1);
    while(n--){
        int x;
        cin >> x;
        freq[x]++;
    }

    int ans = 0;
    for(int i=1e6; i>=1 and !ans; --i){
        int cnt = freq[i];
        for(int j=i+i; j<=1e6; j+=i)
            cnt += freq[j];
        if(cnt >= 2)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}
