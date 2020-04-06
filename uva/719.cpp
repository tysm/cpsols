#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        s += s;
        int n = s.size();
        int i = 0, ans = 0;
        while(i < n/2){
            ans = i;
            int j = i+1, k = i;
            while(j < n and s[k] <= s[j]){
                if(s[k] < s[j])
                    k = i;
                else
                    k++;
                j++;
            }
            while(i <= k)
                i += j - k;
        }
        cout << ans+1 << endl;
    }
    return 0;
}
