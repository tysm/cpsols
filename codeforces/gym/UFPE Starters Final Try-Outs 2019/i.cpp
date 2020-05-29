#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/linear-diophantine-equation.hpp>

int32_t main(){
    desync();
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi ans = lde(arr, b-a);
    for(int i=0; i<n; ++i)
        cout << (ans[i] > 0? ans[i] : 0) << endl;
    for(int i=0; i<n; ++i)
        cout << (ans[i] < 0? -ans[i] : 0) << endl;
    return 0;
}
