#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int a, b;
    cin >> a >> b;
    int x = 0;
    for(int i=1; i<=2e5; ++i){
        if(a+b >= (i+1)*i/2)
            x = i;
    }
    set<int> av, bv;
    for(int i=x; i>=1; --i){
        if(a){
            if(a >= i){
                av.emplace(i);
                a -= i;
            }
            else{
                av.emplace(a);
                a = 0;
            }
        }
        if(!av.count(i) and b >= i){
            bv.emplace(i);
            b -= i;
        }
    }
    cout << av.size() << endl;
    cout << vi(all(av)) << endl;
    cout << bv.size() << endl;
    cout << vi(all(bv)) << endl;
    return 0;
}
