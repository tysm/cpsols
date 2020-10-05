#include <cpplib/stdinc.hpp>
#include <cpplib/math/gries-misra.hpp>

int32_t main(){
    Sieve sv(N);

    desync();
    int n, m;
    cin >> n >> m;
    if(n == 2){
        cout << 2 << ' ' << 2 << endl;
        cout << 1 << ' ' << 2 << ' ' << 2 << endl;
        return 0;
    }

    vvii adj(n+1);
    adj[1].eb(n, 2);
    m--;

    int acc = 2;
    for(int i=2; i<=n-2; ++i){
        acc++;
        adj[1].eb(i, 1);
        m--;
    }
    acc++;
    int w = 1;
    while(!sv.is_prime(acc)){
        acc++;
        w++;
    }
    adj[1].eb(n-1, w);
    m--;

    for(int i=2; i<=n and m; ++i){
        for(int j=i+1; j<=n and m; ++j){
            adj[i].eb(j, 1e9);
            m--;
        }
    }

    cout << 2 << ' ' << acc << endl;
    for(int i=1; i<=n; ++i){
        for(ii j:adj[i]){
            cout << i << ' ' << j.ff << ' ' << j.ss << endl;
            m--;
        }
    }
    return 0;
}
