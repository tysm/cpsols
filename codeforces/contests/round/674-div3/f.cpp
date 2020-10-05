#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = 0, m = 0;
    for(char c:s){
        if(c == 'a')
            a++;
        else if(c == '?')
            m++;
    }

    mint ans = 0;
    int c = 0, k = 0;
    for(int i=n-1; i>=0; --i){
        a -= (s[i] == 'a');
        m -= (s[i] == '?');
        if(s[i] == 'b' or s[i] == '?'){
            ans += exp(mint(3), m)*mint(a) * exp(mint(3), k)*mint(c);
            if(m)
                ans += exp(mint(3), m-1)*mint(m) * exp(mint(3), k)*mint(c);
            if(k)
                ans += exp(mint(3), m)*mint(a) * exp(mint(3), k-1)*mint(k);
            if(m and k)
                ans += exp(mint(3), m-1)*mint(m) * exp(mint(3), k-1)*mint(k);
        }
        c += (s[i] == 'c');
        k += (s[i] == '?');
    }
    cout << ans << endl;
    return 0;
}
