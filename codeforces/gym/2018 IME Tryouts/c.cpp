#include <cpplib/stdinc.hpp>

vi regs;
int grid[6][6];
vector<bitset<7> > inreg, inrow(6), incol(6), inblo(6);

int block(ii pos){
    int i = pos.ff, j = pos.ss;
    return i < 2? (j < 3? 0 : 1) : (i < 4? (j < 3? 2 : 3) : (j < 3? 4 : 5));
}

bool check(ii pos, int k){
    int i = pos.ff, j = pos.ss, r = grid[i][j], b = block(pos);
    if(inrow[i][k] or incol[j][k] or inreg[r][k] or inblo[b][k] or regs[r] - k < 0)
        return false;
    return true;
}

int ans[6][6];

bool solve(ii pos = {0, 0}){
    if(pos == ii(6, 0))
        return true;
    ii next_pos = (pos.ss < 5? ii(pos.ff, pos.ss+1) : ii(pos.ff+1, 0));
    int i = pos.ff, j = pos.ss, r = grid[i][j], b = block(pos);
    for(int k=1; k<=6; ++k){
        if(!check(pos, k))
            continue;
        inreg[r][k] = inrow[i][k] = incol[j][k] = inblo[b][k] = 1;

        ans[i][j] = k;

        regs[r] -= k;
        if(solve(next_pos))
            return true;
        regs[r] += k;

        inreg[r][k] = inrow[i][k] = incol[j][k] = inblo[b][k] = 0;
    }
    return false;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    regs.resize(n);
    inreg.resize(n);
    for(int &i:regs)
        cin >> i;
    for(int i=0; i<36; ++i){
        cin >> grid[i/6][i%6];
        grid[i/6][i%6]--;
    }
    solve();
    for(int i=0; i<36; ++i)
        cout << ans[i/6][i%6] << " \n"[(i+1)%6 == 0];
    return 0;
}
