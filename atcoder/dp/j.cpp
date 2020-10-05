#include <cpplib/stdinc.hpp>

int n;
double dp[(int)3e2+1][(int)3e2+1][(int)3e2+1];

double solve(int a, int b, int c){
    double &res = dp[a][b][c];
    if(res + EPS < 0){
        res = n;
        if(a)
            res += a*solve(a-1, b+1, c);
        if(b)
            res += b*solve(a, b-1, c+1);
        if(c)
            res += c*solve(a, b, c-1);
        res /= (a + b + c);
    }
    return res;
}

int32_t main(){
    desync();
    cin >> n;
    int a = 0, b = 0, c = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x == 3)
            a++;
        else if(x == 2)
            b++;
        else
            c++;
    }
    for(int i=0; i<3e2+1; ++i){
        for(int j=0; j<3e2+1; ++j){
            for(int k=0; k<3e2+1; ++k)
                dp[i][j][k] = -1;
        }
    }
    dp[0][0][0] = 0;
    cout << fixed << setprecision(15) << solve(a, b, c) << endl;
    return 0;
}
