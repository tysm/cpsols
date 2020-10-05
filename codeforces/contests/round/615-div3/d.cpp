#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int q, x;
    cin >> q >> x;
    set<int> mexs;
    for(int i=0; i<=4e5; ++i)
        mexs.insert(i);
    map<int, int> cnt;
    while(q--){
        int a;
        cin >> a;
        a %= x;
        if(cnt[a]){
            int v = cnt[a];
            mexs.erase(v);
            cnt[a] = v+x;
        }
        else{
            mexs.erase(a);
            cnt[a] = a+x;
        }
        cout << *mexs.begin() << endl;
    }
    return 0;
}
