#include <cpplib/stdinc.hpp>
#define double long double

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;

        string ns = to_string(n);
        int m = ns.size();

        vi sum(m);
        for(int i=0; i<m; ++i){
            sum[i] = ns[i]-'0';
            if(i)
                sum[i] += sum[i-1];
        }

        int ans = 0, ok = false;
        for(int i=m-1; i>=0; --i){
            if(sum[i] <= s){
                ok = true;
                break;
            }
            if(ns[i] != '0'){
                int d = (10 - (int)(ns[i]-'0'));
                for(int j=0; j<m-(i+1); ++j)
                    d *= 10;
                ans += d;
                for(int j=i-1; j>=0; --j){
                    ns[j]++;
                    if(ns[j] <= '9')
                        break;
                    ns[j] = '0';
                }
                for(int j=0; j<i; ++j){
                    sum[j] = ns[j]-'0';
                    if(j)
                        sum[j] += sum[j-1];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
