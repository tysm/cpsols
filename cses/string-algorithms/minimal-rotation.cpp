#include <cpplib/stdinc.hpp>
#include <cpplib/string/lyndon-factorization.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1110
    desync();
    string s;
    cin >> s;
    int n = s.size();
    s += s.substr(0, n-1);
    vii factors = lyndon_factorization(s);
    int ans = factors[0].ff;
    for(int i=1; i<factors.size() and factors[i].ff < n; ++i)
        ans = factors[i].ff;
    cout << s.substr(ans, n) << endl;
    return 0;
}
