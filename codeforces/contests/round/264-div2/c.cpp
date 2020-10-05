#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int n;

int get_dg0(int i, int j){
    return n+i-(j+1);
}

int get_dg1(int i, int j){
    return n+i-(n-j);
}

int32_t main(){
    desync();
    cin >> n;
    vvi diag(2, vi(2*n)), grid(n, vi(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> grid[i][j];
            diag[0][get_dg0(i, j)] += grid[i][j];
            diag[1][get_dg1(i, j)] += grid[i][j];
        }
    }
    ii ans[2];
    int res[2] = {-1, -1};
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int d = (i+j)%2, dg0 = get_dg0(i, j), dg1 = get_dg1(i, j);
            int sum = diag[0][dg0] + diag[1][dg1] - grid[i][j];
            if(sum > res[d]){
                ans[d] = {i+1, j+1};
                res[d] = sum;
            }
        }
    }
    cout << res[0] + res[1] << endl;
    for(int i=0; i<2; ++i)
        cout << ans[i].ff << ' ' << ans[i].ss << " \n"[i];
    return 0;
}
