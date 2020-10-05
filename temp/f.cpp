#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics/modular.hpp>

int32_t main(){
    desync();
    ModC<> combs(1e3);

    int n, m;
    cin >> n >> m;
    vi arr(m);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));

    mint ans = combs.fact(n-m);
    for(int i=0; i<m; ++i){
        int b = arr[i] - (i? arr[i-1]+1 : 1);
        ans *= combs.inv(combs.fact(b));
        if(i and b)
            ans *= exp((mint)2, b-1);
    }
    ans *= combs.inv(combs.fact(n+1 - (arr[m-1]+1)));
    cout << ans << endl;
    return 0;
}
