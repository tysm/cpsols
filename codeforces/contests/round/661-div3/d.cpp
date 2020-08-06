#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int acc = 0;
        vi ans(n);
        vvi aux(2);
        for(int i=0; i<n; ++i){
            char c = s[i];
            if(c == '0'){
                if(aux[0].empty()){
                    acc++;
                    aux[1].eb(acc);
                    ans[i] = acc;
                }
                else{
                    ans[i] = aux[0].back();
                    aux[0].pop_back();
                    aux[1].eb(ans[i]);
                }
            }
            else{
                if(aux[1].empty()){
                    acc++;
                    aux[0].eb(acc);
                    ans[i] = acc;
                }
                else{
                    ans[i] = aux[1].back();
                    aux[1].pop_back();
                    aux[0].eb(ans[i]);
                }
            }
        }
        cout << acc << endl;
        cout << ans << endl;
    }
    return 0;
}
