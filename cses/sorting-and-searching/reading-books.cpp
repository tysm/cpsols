#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1631
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(arr.begin(), arr.end());

    vi psum(arr);
    for(int i=1; i<n; ++i)
        psum[i] += psum[i-1];

    int ans = psum[n-1];
    if(n > 1 and psum[n-2] < arr[n-1])
        ans += arr[n-1] - psum[n-2];
    cout << (n > 1? ans : ans*2) << endl;
    // by bfs.07
    return 0;
}
