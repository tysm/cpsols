#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int xl;
        string l;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            string s;
            if(i){
                s = l;
                int aux = 1;
                while(s[xl] == s[xl+aux])
                    aux++;
                swap(s[xl], s[xl+aux]);
            }
            else{
                for(int j=0; j<200; ++j)
                    s += (char)('a' + j%26);
            }
            cout << s << endl;
            l = s;
            xl = x;
        }
        int aux = 1;
        while(l[xl] == l[xl+aux])
            aux++;
        swap(l[xl], l[xl+aux]);
        cout << l << endl;
    }
    return 0;
}
