#include <cpplib/stdinc.hpp>
#include <cpplib/string/matching/rabin-karp.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1753
    desync();
    string t, p;
    cin >> t >> p;
    cout << rabin(p, t).size() << endl;
    return 0;
}
