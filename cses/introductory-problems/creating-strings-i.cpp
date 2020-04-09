#include <cpplib/stdinc.hpp>

void solve(vi &acc, string ans = ""){
    bool end = true;
    for(int i=0; i<26; ++i){
        if(acc[i] > 0){
            end = false;
            acc[i]--;
            solve(acc, ans + (char)('a'+i));
            acc[i]++;
        }
    }
    if(end)
        cout << ans << endl;
}

int fac(int n){
    if(n <= 1)
        return 1;
    return n*fac(n-1);
}

int32_t main(){
    // https://cses.fi/problemset/task/1622
    desync();
    string s;
    cin >> s;

    int n = fac(s.size());
    vi acc(26);
    for(char c:s)
        acc[c-'a']++;
    for(int i:acc)
        n /= fac(i);
    cout << n << endl;
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
    // solve(acc);
    return 0;
}
