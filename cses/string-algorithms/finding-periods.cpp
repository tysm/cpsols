#include <cpplib/stdinc.hpp>
#include <cpplib/string/z-function.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1733
    desync();
    string s;
    cin >> s;
    vi z = z_function(s);
    for(int i=1; i<s.size(); ++i){
        if(z[i] == s.size()-i)
            cout << i << ' ';
    }
    cout << s.size() << endl;
    return 0;
}
