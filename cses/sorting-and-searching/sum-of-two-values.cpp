#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1640
    desync();
    int n, x;
    cin >> n >> x;

    vii v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].ff;
        v[i].ss = i+1;
    }
    sort(v.begin(), v.end());

    int i=0, j=n-1;
    while(i<j){
        int sum = v[i].ff + v[j].ff;
        if(sum > x)
            j--;
        else if (sum == x){
            cout << v[i].ss << ' ' << v[j].ss << endl;
            return 0;
        }
        else
            i++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
