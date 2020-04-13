#include <cpplib/stdinc.hpp>
#include <cpplib/string/distance/levenshtein.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1639
    desync();
    string a, b;
    cin >> a >> b;
    vvi dis = distance(a, b);
    cout << dis[a.size()][b.size()] << endl;
    return 0;
}
