#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>

template<typename T, size_t N>
matrix<T, N> mult(matrix<T, N> &lhs, matrix<T, N> &rhs)
{
    // NOTE: this is not a floyd warshall!
    // Here we combine two matrices without
    // using the new updated value in later
    // updates.
    matrix<T, N> res(LINF);
    for(uint k=0; k<N; ++k){
        for(uint i=0; i<N; ++i){
            for(uint j=0; j<N; ++j){
                if(lhs[i][k] != LINF and rhs[k][j] != LINF)
                    res[i][j] = min(res[i][j], lhs[i][k] + rhs[k][j]);
            }
        }
    }
    return res;
}

template<typename T, size_t N>
matrix<T, N> expsp(matrix<T, N> b, uint e)
{
    matrix<T, N> res(LINF);
    for(uint i=0; i<N; ++i)
        res[i][i] = 0;
    for(; e > 0; e >>= 1){
        if(e & 1)
            res = mult(res, b);
        b = mult(b, b);
    }
    return res;
}

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    matrix<int, 100> one(LINF);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        one[u-1][v-1] = w;
    }
    one = expsp(one, k);

    int ans = LINF;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(one[i][j] == LINF)
                continue;
            ans = min(ans, one[i][j]);
        }
    }
    if(ans == LINF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
    return 0;
}
