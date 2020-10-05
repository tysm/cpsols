#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        s1+=x;
    }
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        s2+=x;
    }
    cout << (s1 >= s2? "YES" : "NO") << endl;
    return 0;
}
