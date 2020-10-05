#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi ans(3);
    for(int &i:ans)
        cin >> i;
    for(int i=1; i<n; ++i){
        vi aux(3);
        for(int &j:aux)
            cin >> j;
        vi res(3);
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                if(k == j)
                    continue;
                res[j] = max(res[j], ans[k] + aux[j]);
            }
        }
        swap(ans, res);
    }
    cout << *max_element(all(ans)) << endl;
    return 0;
}
