#include <cpplib/stdinc.hpp>
#include <cpplib/string/lcs.hpp>

int32_t main(){
    desync();
    string a, b;
    cin >> a >> b;

    string res = lcs(a, b);
    cout << res.size() << endl;

    for(int i=0, j=0; j<res.size(); ++i){
        if(res[j] == a[i])
            cout << i+1 << " \n"[++j == res.size()];
    }
    for(int i=0, j=0; j<res.size(); ++i){
        if(res[j] == b[i])
            cout << i+1 << " \n"[++j == res.size()];
    }

    return 0;
}
