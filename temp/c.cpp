#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, h;
    cin >> n >> m >> h;
    n--;
    int sum = 0, hx;
    for(int i=1; i<=m; ++i){
        int x;
        cin >> x;
        if(i != h)
            sum += x;
        else
            hx = x-1;
    }
    if(sum+hx< n)
        cout << -1 << endl;
    else{
        double acc = 1, ans = 0;
        for(int i=0; i<n; ++i){
            ans += acc*(double)hx/(sum+hx);
            acc *= (double)sum/(sum+hx);
            sum--;
        }
        cout << ans << endl;
    }
    return 0;
}
