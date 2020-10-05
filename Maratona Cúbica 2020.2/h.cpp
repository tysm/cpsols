#include <cpplib/stdinc.hpp>
#include <cpplib/string/rabin-karp.hpp>

int32_t main(){
    desync();
    string s, w;
    cin >> s >> w;

    string aux = w;
    reverse(all(aux));

    auto iv = rabin(w, s), jv = rabin(aux, s);
    int j = 0, ans = 0;
    for(int i=0; i<iv.size() and j < jv.size(); ++i){
        while(j < jv.size() and iv[i] + w.size() > jv[j])
            j++;
        ans += jv.size() - j;
    }
    cout << ans << endl;

    return 0;
}
