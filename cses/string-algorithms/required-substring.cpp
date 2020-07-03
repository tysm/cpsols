#include <cpplib/stdinc.hpp>
#include <cpplib/string/prefix-function.hpp>

int n, m;
string s;
vi pi;
int dp[1000][100][2];

int solve(int i, int j, bool has){
    if(i == n)
        return has;
    int &res = dp[i][j][has];
    if(res == -1){
        res = 0;
        for(char c='A'; c<='Z'; ++c){
            int aux = j;
            while(aux > 0 and c != s[aux])
                aux = pi[aux-1];
            if(c == s[aux])
                aux++;
            res = mod(res + solve(i+1, aux%m, has or aux == m));
        }
    }
    return res;
}

int32_t main(){
    desync();
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> s;
    m = s.size();
    pi = prefix_function(s + '#');
    cout << solve(0, 0, false) << endl;
    return 0;
}
