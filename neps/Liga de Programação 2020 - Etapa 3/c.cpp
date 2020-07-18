#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi ans(n);
    for(int i=1; i<n; ++i){
        if(s[i-1] == 'A')
            ans[i] = ans[i-1] + 1;
        else
            ans[i] = ans[i-1] - 1;
    }
    int acc = *min_element(all(ans));
    for(int &i:ans)
        i -= acc;
    cout << ans << endl;
    return 0;
}
