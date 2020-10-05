#include <cpplib/stdinc.hpp>
#include <cpplib/array/kadane.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi a1, a2;
    for(int i=0; i<n-1; ++i)
        a1.eb(abs(arr[i]-arr[i+1])*(i%2? -1 : 1));
    for(int i=1; i<n-1; ++i)
        a2.eb(abs(arr[i]-arr[i+1])*(i%2? 1 : -1));
    cout << max(kadane(a1).ff, kadane(a2).ff) << endl;
    return 0;
}
