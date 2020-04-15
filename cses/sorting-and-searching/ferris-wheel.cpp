#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1090
    desync();
    int n, x;
    cin >> n >> x;
    vi v(n);
    for(int &i:v)
        cin >> i;
    sort(v.begin(), v.end());
    int i=0, j=n-1, ans = 0;
    while(i <= j){
        ans++;
        int a = v[i], b = v[j];
        if(i != j and v[i] + v[j] <= x)
            i++;
        j--;
    }
    cout << ans << endl;
    return 0;
}
