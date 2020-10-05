#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>
#include <cpplib/adt/matrix.hpp>

const int N = 101;

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n), cnt(2);
    for(int &i:arr){
        cin >> i;
        cnt[i]++;
    }

    mint tot = n*(n-1)/2;

    matrix<mint, N> c(0);
    for(int o0=min(cnt[0], cnt[1]), z0=cnt[0]-o0; o0>=0 and z0<=cnt[0]; --o0, ++z0){
        int o1 = cnt[1] - o0, z1 = cnt[0] - z0;

        mint ops = 0;
        if(o0+1 <= cnt[1] and z1+1 <= cnt[0]){
            c[z0][z0-1] += (o0+1)*(z1+1);
            ops += c[z0][z0-1];
        }
        if(o1+1 <= cnt[1] and z0+1 <= cnt[0]){
            c[z0][z0+1] += (z0+1)*(o1+1);
            ops += c[z0][z0+1];
        }

        c[z0][z0] = tot - (z0*o1 + o0*z1);
    }

    matrix<mint, N, 1> b(0);

    int acc = 0;
    for(int i=0; i<cnt[0]; ++i)
        acc += 1-arr[i];
    b[acc][0] = 1;

    auto res = exp(c, k)*b;

    mint p = res[cnt[0]][0];

    mint q = 0;
    for(int z=0; z<=cnt[0]; ++z)
        q += res[z][0];

    cout << p/q << endl;
    return 0;
}
