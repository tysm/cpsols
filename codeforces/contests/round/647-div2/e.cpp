#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    vi cnt(MAX);
    set<int> ids;
    while(t--){
        int n, p;
        cin >> n >> p;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        if(p == 1){
            cout << n%2 << endl;
            continue;
        }
        sort(rall(arr));
        for(int i:arr){
            bool empty = ids.empty();
            cnt[i]++;
            ids.insert(-i);
            if(!empty){
                while(i < -(*ids.begin()) and cnt[i] == p){
                    cnt[i] = 0;
                    ids.erase(-i);
                    i++;
                    cnt[i]++;
                    ids.insert(-i);
                }
                if(i == -(*ids.begin())){
                    while(!ids.empty() and cnt[i] >= 2){
                        cnt[i] %= 2;
                        if(!cnt[i]){
                            ids.erase(-i);
                            if(!ids.empty())
                                i = -(*ids.begin());
                        }
                    }
                }
            }
        }
        if(ids.empty())
            cout << 0 << endl;
        else{
            int ans = bexpm(p, -(*ids.begin()));
            cnt[-(*ids.begin())] = 0;
            ids.erase(ids.begin());
            for(int i:ids){
                ans = mod(ans - mod(cnt[-i]*bexpm(p, -i)));
                cnt[-i] = 0;
            }
            ids.clear();
            cout << ans << endl;
        }
    }
    return 0;
}
