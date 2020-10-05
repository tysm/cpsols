#include <cpplib/stdinc.hpp>

int m, na, nb, t;
vi arra, arrb;

map<ii, bool> dp[2];

bool solve(int i, int j, int tree){
    if(tree == 0 and i > na-m)
        return false;
    if(tree == 1 and i > nb-m)
        return false;
    if(dp[tree].count({i, j}))
        return dp[tree][{i, j}];
    bool &res = dp[tree][{i, j}];
    if(tree == 0){
        for(int k=j; k<=nb-m; ++k){
            if(abs(arra[i] - arrb[k]) >= t or abs(arra[i+m-1] - arrb[k+m-1]) >= t)
                continue;
            if(solve(k, i+m, 1))
                res = 1;
        }
    }
    else{
        for(int k=j; k<=na-m; ++k){
            if(abs(arrb[i] - arra[k]) >= t or abs(arrb[i+m-1] - arra[k+m-1]) >= t)
                continue;
            if(solve(k, i+m, 0))
                res = 1;
        }
    }
    return res;
}

int32_t main(){
    desync();
    cin >> m >> na >> nb >> t;
    for(int i=0; i<na; ++i){
        int x;
        cin >> x;
        arra.pb(x);
    }
    sort(all(arra));
    for(int i=0; i<nb; ++i){
        int x;
        cin >> x;
        arrb.pb(x);
    }
    sort(all(arrb));
    bool valid = false;
    for(int i=0; i<=nb; ++i)
        dp[0][{na-m, i}] = true;
    if(solve(0, 0, 1))
        valid = true;
    dp[0].clear();
    dp[1].clear();
    for(int i=0; i<=na; ++i)
        dp[1][{nb-m, i}] = true;
    if(solve(0, 0, 0))
        valid = true;
    cout << (valid? 'S' : 'N') << endl;
    return 0;
}
