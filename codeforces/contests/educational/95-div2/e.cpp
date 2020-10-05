#include <cpplib/stdinc.hpp>
#undef MOD
#define MOD ((int)998244353LL)
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));

    vi psum(arr);
    for(int i=1; i<n; ++i)
        psum[i] += psum[i-1];

    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;

        int sml = lower_bound(all(arr), b) - arr.begin();
        int big = n-sml;

        if(big < a){
            cout << 0 << endl;
            continue;
        }

        mint sml_sum = (sml? psum[sml-1] : 0);
        mint big_sum = psum[n-1] - sml_sum;

        //mint big_ans = big_sum*(big-a)/big;
        //mint sml_ans = sml_sum*(big+1-a)/(big+1);
        mint big_ans = big_sum - big_sum*a/big;
        mint sml_ans = sml_sum - sml_sum*a/(big+1);
        cout << big_ans + sml_ans << endl;
    }
    return 0;
}
