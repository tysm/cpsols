#include <cpplib/stdinc.hpp>

int dp[5][(int)1e5+1], val[] = {1, 5, 10, 20, 50};

bool solve(int idx, int k, vi &cur){
    if(!k)
        return true;
    if(k < 0)
        return false;
    if(idx == 4)
        return k%50 == 0 and k/50 <= cur[4];

    int &res = dp[idx][k];
    if(res == -1){
        res = false;
        for(int i=0; i<=cur[idx]; ++i){
            if(solve(idx+1, k-val[idx]*i, cur))
                res = true;
        }
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi arr(m);
        for(int &i:arr)
            cin >> i;
        vi ans;
        int maxx = LINF;
        for(int a=0; a<=8; ++a){
            for(int b=0; b<=2; ++b){
                for(int c=0; c<=2; ++c){
                    for(int d=0; d<=4; ++d){
                        int sum = a*1 + b*5 + c*10 + d*20;
                        if(sum > n || (n-sum)%50)
                            continue;
                        int e = (n-sum)/50;
                        sum = n;

                        vi cur = {a, b, c, d, e};

                        bool ok = true;
                        memset(dp, -1, sizeof(dp));
                        for(int i:arr){
                            if(!solve(0, i, cur)){
                                ok = false;
                                break;
                            }
                        }

                        int ctot = a+b+c+d+e;
                        if(ok and ctot < maxx){
                            maxx = ctot;
                            ans = cur;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
