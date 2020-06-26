#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool win = false;
        stack<char> st;
        for(char c:s){
            if(st.empty() or st.top() == c)
                st.push(c);
            else{
                st.pop();
                win ^= true;
            }
        }
        cout << (win? "DA" : "NET") << endl;
    }
    return 0;
}
