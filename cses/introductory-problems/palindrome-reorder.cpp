#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1755
    desync();
    string s;
    cin >> s;

    int acc[26] = {};
    for(char c:s)
        acc[c-'A']++;

    int ods = 0;
    for(int i:acc)
        ods += i%2;

    if(ods > 1)
        cout << "NO SOLUTION" << endl;
    else{
        string ans;
        for(int i=0; i<26; ++i){
            for(int j=0; j<acc[i]/2; ++j)
                ans += 'A'+i;
        }
        for(int i=0; i<26; ++i){
            if(acc[i]%2)
                ans += 'A'+i;
        }
        for(int i=25; i>=0; --i){
            for(int j=0; j<acc[i]/2; ++j)
                ans += 'A'+i;
        }
        cout << ans << endl;
    }
    return 0;
}
