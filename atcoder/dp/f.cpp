#include <cpplib/stdinc.hpp>
#include <cpplib/string/longest-commom-subsequence.hpp>

int32_t main(){
    desync();
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
    return 0;
}
