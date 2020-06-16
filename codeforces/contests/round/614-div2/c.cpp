#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    vvb grid(2, vb(n));
    int acc = 0;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        if(grid[i][j]){
            grid[i][j] = false;
            if(grid[(i+1)%2][j])
                acc--;
            if(j < n-1 and grid[(i+1)%2][j+1])
                acc--;
            if(j > 0 and grid[(i+1)%2][j-1])
                acc--;
        }
        else{
            grid[i][j] = true;
            if(grid[(i+1)%2][j])
                acc++;
            if(j < n-1 and grid[(i+1)%2][j+1])
                acc++;
            if(j > 0 and grid[(i+1)%2][j-1])
                acc++;
        }
        if(!acc)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
