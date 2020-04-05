#include <cpplib/stdinc.hpp>
#include <cpplib/string/manacher.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1111
    desync();
    string s;
    cin >> s;
    ii bounds = manacher(s);
    cout << s.substr(bounds.ff, bounds.ss - bounds.ff + 1) << endl;
    return 0;
}
