#include <cpplib/stdinc.hpp>
#include <cpplib/array/longest-increasing-subsequence.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1145
    desync();
    int n;
    cin >> n;
    vi seq(n);
    for(int &i:seq)
        cin >> i;
    cout << lis(seq).size() << endl;
    return 0;
}
