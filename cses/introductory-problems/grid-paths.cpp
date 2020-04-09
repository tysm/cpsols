#include <cpplib/stdinc.hpp>

string s;
bool vis[7][7];

int d[] = {-1, 1, 0, 0};

int solve(int k, int i, int j){
    if(k == 48) return 1;
    if(vis[6][0]) return 0;

    if((i == 0 or vis[i-1][j]) and (i == 6 or vis[i+1][j]) and 0 < j and j < 6 and !vis[i][j-1] and !vis[i][j+1]) return 0;
    if((j == 0 or vis[i][j-1]) and (j == 6 or vis[i][j+1]) and 0 < i and i < 6 and !vis[i-1][j] and !vis[i+1][j]) return 0;

    if(s[k] == '?'){
        int ans = 0;
        for(int di = 0; di<4; ++di){
            int ki = i + d[di], kj = j + d[3-di];
            if(ki < 0 or ki > 6) continue;
            if(kj < 0 or kj > 6) continue;
            if(vis[ki][kj]) continue;
            vis[ki][kj] = true;
            ans += solve(k+1, ki, kj);
            vis[ki][kj] = false;
        }
        return ans;
    }
    if(s[k] == 'U') i--;
    else if(s[k] == 'D') i++;
    else if(s[k] == 'L') j--;
    else j++;
    if(i < 0 or i > 6) return 0;
    if(j < 0 or j > 6) return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = true;
    int ans = solve(k+1, i, j);
    vis[i][j] = false;
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1625
    desync();
    cin >> s;
    vis[0][0] = true;
    cout << solve(0, 0, 0) << endl;
    vis[0][0] = false;
    return 0;
}
