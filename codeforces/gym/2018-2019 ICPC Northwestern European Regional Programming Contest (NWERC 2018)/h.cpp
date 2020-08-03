#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k, m;
    cin >> n >> k >> m;
    vi ans(n);
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        ans[x-1] = 2;
    }
    int i = 1;
    if(k%2){
        ans[0] = 1;
        i++;
        k--;
    }
    while(k){
        if(ans[i] == 2){
            i++;
            continue;
        }
        ans[i] = 1;
        i += 2;
        k -= 2;
    }
    string s;
    for(int i:ans)
        s += (char)('0' + (i == 1));
    cout << s << endl;
    return 0;
}
