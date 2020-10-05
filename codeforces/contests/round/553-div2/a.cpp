#include <cpplib/stdinc.hpp>

int solve(string s){
    string t = "ACTG";

    int res = 0;
    for(int i=0; i<4; ++i){
        if(s[i] > t[i])
            res += min(s[i]-t[i], 'Z'-s[i] + t[i]-'A' + 1);
        else
            res += min(t[i]-s[i], 'Z'-t[i] + s[i]-'A' + 1);
    }
    return res;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = INF;
    for(int i=0; i<=n-4; ++i)
        ans = min(ans, solve(s.substr(i, 4)));
    cout << ans << endl;
    return 0;
}
