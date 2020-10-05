#include <cpplib/stdinc.hpp>

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();

        vi arr(all(s));
        for(int &i:arr)
            i -= '0';

        vi vis(n), cur(10), res;
        for(int k=0; k<n; ++k){
            for(int i=0; i<10; ++i){
                int &c = cur[i];
                while(c < n and (vis[c] or i%2 + arr[c]%2 == 1))
                    c++;
            }
            for(int i=0; i<10; ++i){
                int c = cur[i];
                if(c >= n)
                    continue;
                if(arr[c] != i)
                    continue;
                res.eb(i);
                vis[c] = true;
                break;
            }
        }
        string ans(all(res));
        for(char &c:ans)
            c += '0';
        cout << ans << endl;
    }
    return 0;
}
