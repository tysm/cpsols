#include <cpplib/stdinc.hpp>

bool match(string &s, string &r){
    int n = r.size();
    if(s.size() == n)
        return s == r;
    if(s.substr(0, n-1) != r.substr(0, n-1))
        return false;
    return s[n-1] == r[n-1] or s[n-1]+1 == r[n-1];
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string num, d;
        cin >> num;
        int n = 0, m = 0;
        bool found = false;
        for(char c:num){
            if(c == '.'){
                found = true;
                continue;
            }
            if(found){
                d += c;
                m *= 10;
                m += c - '0';
            }
            else{
                n *= 10;
                n += c - '0';
            }
        }
        if(n)
            cout << n;
        if(m){
            if(n)
                cout << ' ';
            bool ok = false;
            for(int b = 2; b <= 128 and !ok; b *= 2){
                for(int a = 1; a < b and !ok; ++a){
                    string x;
                    int aux = a;
                    for(int i=0; i<6; ++i){
                        aux *= 10;
                        x += (char)(aux/b + '0');
                        aux %= b;
                    }
                    if(aux){
                        aux *= 10;
                        x += (char)(aux/b + '0');
                        aux %= b;
                    }
                    if(match(x, d)){
                        cout << a << '/' << b;
                        ok = true;
                    }
                }
            }
        }
        cout << "\"" << endl;
    }
    return 0;
}
