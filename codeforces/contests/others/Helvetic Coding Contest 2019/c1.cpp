#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    n = 4*n + 1;

    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    int ans = -1;
    for(int l=1; l<=50 and ans == -1; ++l){
        for(int x=0; x+l<=50 and ans == -1; ++x){
            for(int y=0; y+l<=50 and ans == -1; ++y){
                set<int> res;
                for(int i=0; i<n; ++i){
                    ii p = arr[i];
                    if((p.ff == x or p.ff == x+l) and p.ss >= y and p.ss <= y+l)
                        continue;
                    if((p.ss == y or p.ss == y+l) and p.ff >= x and p.ff <= x+l)
                        continue;
                    res.emplace(i);
                }
                if(res.size() == 1)
                    ans = *res.begin();
            }
        }
    }
    cout << arr[ans].ff << ' ' << arr[ans].ss << endl;
    return 0;
}
