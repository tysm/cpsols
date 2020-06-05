#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    int n, m, minv = 0, maxv = 1e9;
    cin >> n >> m;
    m *= 8;
    vi arr(n);
    ost_set<int> ost;
    for(int &i:arr){
        cin >> i;
        ost.insert(i);
    }
    sort(all(arr));

    int k = 19;
    while(k > 0 and k*n > m)
        k--;
    k = bexp(2, k);
    if(k >= ost.size())
        cout << 0 << endl;
    else{
        int ans = n;
        for(int i=0; i+k <= ost.size(); ++i){
            int l = *ost.find_by_order(i), r = *ost.find_by_order(i+k-1);
            int auxl = lower_bound(all(arr), l) - arr.begin();
            int auxr = arr.end() - upper_bound(all(arr), r);
            ans = min(ans, auxl+auxr);
        }
        cout << ans << endl;
    }
    return 0;
}
