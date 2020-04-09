#include <cpplib/stdinc.hpp>

vector<string> board(8);
vector<bool> qrow(8);

bool safe(int i, int j){
    if(board[i][j] != '.')
        return false;
    if(qrow[i])
        return false;
    for(int ki=i-1, kj=j-1; ki>=0 and kj>=0; --ki, --kj){
        if(board[ki][kj] == 'r')
            return false;
    }
    for(int ki=i+1, kj=j-1; ki<8 and kj>=0; ++ki, --kj){
        if(board[ki][kj] == 'r')
            return false;
    }
    return true;
}

int solve(int j = 0){
    if(j==8)
        return 1;
    int ans = 0;
    for(int i=0; i<8; ++i){
        if(safe(i, j)){
            qrow[i] = true;
            board[i][j] = 'r';
            ans += solve(j+1);
            board[i][j] = '.';
            qrow[i] = false;
        }
    }
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1624
    desync();
    for(string &s:board)
        cin >> s;
    cout << solve() << endl;
    return 0;
}
