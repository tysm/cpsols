#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    int n = s.size();
    vi psum(n);
    for(int i=0; i<n; ++i){
        psum[i] = (s[i] == 'A');
        if(i)
            psum[i] += psum[i-1];
    }
    int acc = psum[n-1];

    if(n%2 == 0){
        for(int i=0; i<n/2; ++i){
            int j = i+n/2-1, sum = psum[j] - (i? psum[i-1] : 0);
            if(sum == acc - sum){
                cout << "YES" << endl;
                cout << i+1 << ' ' << 1+i+n/2 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
