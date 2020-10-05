#include <cpplib/stdinc.hpp>

int n;
vi arr;

int dp[100][10][2];

int solve(int idx, int v, bool lt){
    if(idx == n)
        return 1;
    int &res = dp[idx][v][lt];
    if(res != -1)
        return res;
    res = 0;
    for(int k=v; k<=9; ++k){
        if(lt)
            res += solve(idx+1, k, lt);
        else if(k <= arr[idx])
            res += solve(idx+1, k, k < arr[idx]);
        else
            break;
    }
    return res;
}

bool ramp(string &s){
    for(int i=1; i<s.size(); ++i){
        if(s[i] < s[i-1])
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(!ramp(s)){
            cout << -1 << endl;
            continue;
        }
        n = s.size();
        arr.resize(n);
        for(int i=0; i<n; ++i)
            arr[i] = s[i] - '0';
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, false)-1 << endl;
    }
    return 0;
}
