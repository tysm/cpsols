#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(char c='z'; c>='a'; --c){
        bool rem = false;
        string res, aux;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == c)
                aux += c;
            else{
                if(!rem and s[i] != c-1)
                    res += aux;
                res += s[i];
                rem = (s[i] == c-1);
                aux = "";
            }
        }
        if(!rem)
            res += aux;
        swap(res, s);
    }
    cout << n-s.size() << endl;
    return 0;
}
