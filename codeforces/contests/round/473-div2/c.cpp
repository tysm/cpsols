#include <cpplib/stdinc.hpp>

void dfs(int u, int v, int acc){
    if(!acc)
        return;
    cout << u << ' ' << v << endl;
    dfs(v, v+1, acc-1);
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    if(n <= 5)
        cout << -1 << endl;
    else if(n <= 7){
        cout << 1 << ' ' << 2 << endl;
        cout << 1 << ' ' << 3 << endl;
        cout << 1 << ' ' << 4 << endl;
        cout << 4 << ' ' << 5 << endl;
        cout << 4 << ' ' << 6 << endl;
        if(n == 7)
            cout << 4 << ' ' << 7 << endl;
    }
    else{
        debug(n);
        cout << 1 << ' ' << 2 << endl;
        cout << 1 << ' ' << 3 << endl;
        cout << 2 << ' ' << 4 << endl;
        cout << 3 << ' ' << 5 << endl;
        cout << 2 << ' ' << 6 << endl;
        cout << 6 << ' ' << 7 << endl;
        cout << 6 << ' ' << 8 << endl;
        dfs(6, 9, n-8);
    }

    for(int i=1; i<n; ++i)
        cout << i << ' ' << i+1 << endl;
    return 0;
}
