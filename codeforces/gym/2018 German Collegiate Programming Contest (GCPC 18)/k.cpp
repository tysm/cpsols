#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics.hpp>

int n, m;

double get_l(int i, int j, double k){
    return j + 5*2 + i*10 - (k + i*5);
}

double get_r(int i, int j, double k){
    return j + 5*2 + i*10 - (i+1)*k;
}

bool check(int i, int j, double k){
    double l = get_l(i, j, k);
    double r = get_r(i, j, k);
    if(l >= m+EPS)
        return false;
    if(r <= m-EPS)
        return false;
    return true;
}

int32_t main(){
    desync();

    cin >> n >> m;
    debug(get_l(2, 50, 3.3333333));
    debug(get_r(2, 50, 3.3333333));
    return 0;

    vi arr(n);
    for(int &i:arr){
        cin >> i;
        i -= 10;
    }

    double ans = -1;

    vvb coin(n+1, vb(m+1));
    coin[0][0] = true;
    for(int i=0; i<n; ++i){
        for(int j=m; j>=0; --j){
            int x = arr[i];
            if(coin[i][j] and j+x <= m)
                coin[i+1][j+x] = true;
        }
    }
    for(int i=0; i<=n; ++i){
        debug(i);
        for(int j=0; j<=m; ++j){
            cout << coin[i][j] << " \n"[j == m];
            if(!coin[i][j])
                continue;
            double lo = 0, hi = 5;
            for(int it=0; it<100; ++it){
                double mid = (lo+hi)/2;
                if(check(i, j, mid)){
                    ans = max(ans, mid);
                }
                double l = get_l(i, j, mid), r = get_r(i, j, mid);
                if(r < m + EPS)
                    lo = mid;
                else{
                    if(l >= m+EPS)
                        hi = mid;
                    else
                        lo = mid;
                }
            }
        }
    }
    if(ans < 0)
        cout << "impossible" << endl;
    else
        cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
