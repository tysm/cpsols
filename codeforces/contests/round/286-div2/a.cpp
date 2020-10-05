#include <cpplib/stdinc.hpp>

bool palindrome(const string &s){
    int n = s.size();
    for(int i=0; i<n; ++i){
        if(s[i] != s[n-1-i])
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<=n; ++i){
        string si = s.substr(0, i), sj = s.substr(i);
        for(char c='a'; c<='z'; ++c){
            if(palindrome(si + c + sj)){
                cout << si + c + sj << endl;
                return 0;
            }
        }
    }
    cout << "NA" << endl;
    return 0;
}
