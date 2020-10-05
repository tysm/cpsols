#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    double ans = 0;
    vii arr(n);
    for(auto &[a, b]:arr){
        cin >> a >> b;
        if(b > a)
            swap(a, b);
        ans = max(ans, (double)(a*b)/2);
    }
    sort(rall(arr));

    int mval = 0;
    for(auto [a, b]:arr){
        ans = max(ans, (double)a*min(b, mval));
        mval = max(b, mval);
    }

    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}
