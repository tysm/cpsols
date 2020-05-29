#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    set<char> st;
    cout << "Mike" << endl;
    st.insert(s[0]);
    for(int i=1; i<s.size(); ++i){
        if(*st.begin() < s[i])
            cout << "Ann" << endl;
        else
            cout << "Mike" << endl;
        st.insert(s[i]);
    }
    return 0;
}
