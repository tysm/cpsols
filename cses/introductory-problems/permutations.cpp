#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1070
    desync();
    int n;
    cin >> n;
    if(n == 2 or n == 3)
        cout << "NO SOLUTION" << endl;
    else{
        for(int i=n-(n%2==0); i>=1; i-=2){
            if(i != n-(n%2==0))
                cout << ' ';
            cout << i;
        }
        for(int i=n-(n%2); i>=2; i-=2)
            cout << ' ' << i;
        cout << endl;
    }
    return 0;
}
