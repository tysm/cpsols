#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1092
    desync();
    int n;
    cin >> n;
    int sum = (n*(n+1))/2;
    if(sum%2)
        cout << "NO" << endl;
    else{
        int msum = sum/2;
        vi s1, s2;
        for(int i=n; i>=1; --i){
            if(i <= msum){
                msum -= i;
                s1.pb(i);
            }
            else
                s2.pb(i);
        }
        assert(msum == 0);
        cout << "YES" << endl;
        cout << s1.size() << endl;
        for(int i=0; i<s1.size(); ++i){
            if(i)
                cout << ' ';
            cout << s1[i];
        }
        cout << endl;
        cout << s2.size() << endl;
        for(int i=0; i<s2.size(); ++i){
            if(i)
                cout << ' ';
            cout << s2[i];
        }
        cout << endl;
    }
    return 0;
}
