#include <cpplib/stdinc.hpp>
#include <cpplib/math/gries-misra.hpp>

int n, qcnt;

int query(char c, int x){
    qcnt++;
    if(x > n)
        return 0;

    cout << c << ' ' << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int queryA(int x){
    return query('A', x);
}

int queryB(int x){
    return query('B', x);
}

int32_t main(){
    desync();
    cin >> n;

    Sieve sv(n);
    auto primes = sv.prime_numbers();
    int m = primes.size();

    vi blk, res;
    int i = 0, acc = 0, cur = n;
    for(; i<primes.size(); ++i){
        int p = primes[i];
        acc++;
        blk.eb(p);
        cur -= queryB(p);

        if(acc*acc >= m){
            acc = 0;
            int tot = queryA(1);
            if(tot > cur){
                for(int j:blk){
                    if(!queryB(j))
                        continue;
                    int k = j*j;
                    while(queryB(k))
                        k *= j;
                    res.eb(k/j);
                }
            }
            cur = tot;
            blk.clear();
        }
    }
    if(acc){
            acc = 0;
            int tot = queryA(1);
            if(tot > cur){
                for(int j:blk){
                    if(!queryB(j))
                        continue;
                    int k = j*j;
                    while(queryB(k))
                        k *= j;
                    res.eb(k/j);
                }
            }
            cur = tot;
            blk.clear();
    }
    int ans = 1;
    for(int i:res)
        ans *= i;
    cout << "C " << ans << endl;
    return 0;
}
