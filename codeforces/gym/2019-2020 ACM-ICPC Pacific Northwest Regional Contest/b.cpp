#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi cnt(k+1), arr(n);
    for(int &i:arr){
        cin >> i;
        cnt[i]++;
    }

    vi ans, inans(k+1);
    for(int i:arr){
        cnt[i]--;
        if(!inans[i]){
            while(!ans.empty() and i < ans.back() and cnt[ans.back()]){
                inans[ans.back()] = false;
                ans.pop_back();
            }
            ans.eb(i);
            inans[i] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
