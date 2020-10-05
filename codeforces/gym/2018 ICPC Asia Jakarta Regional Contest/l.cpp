#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int k;
    cin >> k;

    vi arr;
    for(int i=1; i<=k; i<<=1){
        if(k & i)
            arr.eb(1);
        else
            arr.eb(0);
    }
    reverse(all(arr));

    string s;
    cin >> s;

    int ans = 0, n = s.size();

    vi sv;
    sv.eb(s[0] - '0');
    for(int i=1; i<n; ++i){
        if(s[i] == '1' and sv.size() + n-i > arr.size()){
            ans++;
            continue;
        }
        sv.eb(s[i] - '0');
    }
    n = sv.size();

    while(n > arr.size()){
        ans++;
        n--;
    }

    if(sv.size() == arr.size()){
        for(int i=0; i<n; ++i){
            if(arr[i] and !sv[i])
                break;
            if(!arr[i] and sv[i]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
