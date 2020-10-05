#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    map<string, string> rules;
    while(m--){
        string a, b;
        cin >> a >> b;
        rules[a] = b;
    }

    string s = "A";
    while(n--){
        string res, aux;
        for(char c:s){
            if(aux.empty() or aux[0] == c)
                aux += c;
            else{
                if(rules.count(aux))
                    res += rules[aux];
                else
                    res += aux;
                aux.clear();
                aux += c;
            }
        }
        if(rules.count(aux))
            res += rules[aux];
        else
            res += aux;
        aux.clear();
        s = res;
    }
    int ans = 0;
    for(char c:s)
        ans += (c == 'A');
    cout << ans << ' ' << s.size()-ans << endl;
    return 0;
}
