#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    for(int i=0; i<n; ++i){
        char c;
        cin >> c;
        a[m-n+i] = c - 'a';
    }
    for(int i=0; i<m; ++i){
        char c;
        cin >> c;
        b[i] = c - 'a';
    }
    for(int i=m-n-1; i>=0; --i){
        for(int j=0; j<26; ++j){
            if((a[i+n] + j)%26 == b[i+n]){
                a[i] = j;
                break;
            }
        }
    }
    for(char c:a)
        cout << (char)(c + 'a');
    cout << endl;
    return 0;
}
