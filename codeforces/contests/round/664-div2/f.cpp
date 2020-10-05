#include <cpplib/stdinc.hpp>
#include <cpplib/utility/random.hpp>

ii operator+(ii i, const ii &j){
    i.ff += j.ff;
    i.ss += j.ss;
    return i;
}

int dis(const ii &p, const ii &q){
    if((p.ff-q.ff)*(p.ss-q.ss) < 0)
        return abs(p.ff-q.ff) + abs(p.ss-q.ss);
    return max(abs(p.ff-q.ff), abs(p.ss-q.ss));
}

int dis(const ii &p, vector<ii > &arr){
    int res = 0;
    for(ii &q:arr)
        res = max(res, dis(p, q));
    return res;
}

ii conv(string &s){
    ii res;
    for(char c:s){
        res.ff += (c == 'B');
        res.ss += (c == 'N');
    }
    return res;
}

string conv(ii &p){
    string res;
    for(int i=0; i<p.ff; ++i)
        res += 'B';
    for(int i=0; i<p.ss; ++i)
        res += 'N';
    return res;
}

ii rnde(ii cur, vii &arr, int D){
    ii p = {randint(-D, D), randint(-D, D)};
    p = p+cur;
    p.ff = max(p.ff, (int)0);
    p.ss = max(p.ss, (int)0);
    if(dis(p, arr) < dis(cur, arr))
        return p;
    return cur;
}

void solve(vector<ii> &arr, int iter = 2e3){
    ii cur = arr[0];
    for(int i=1; i<arr.size(); ++i)
        cur = cur + arr[i];
    cur.ff /= arr.size();
    cur.ss /= arr.size();

    int res = dis(cur, arr);

    bool r = false;
    for(int i=0; i<iter; ++i){
        ii aux = rnde(cur, arr, randint(1, 1e3*res));
        if(dis(aux, arr) < res){
            res = dis(aux, arr);
            cur = aux;
        }
    }

    if(cur.ff + cur.ss == 0){
        cur = {0, 1};
        res = dis(cur, arr);
        for(ii i: {ii(1, 0), ii(1, 1)}){
            if(dis(i, arr) < res){
                cur = i;
                res = dis(cur, arr);
            }
        }
    }
    cout << res << endl;
    cout << conv(cur) << endl;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<ii> arr;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        arr.eb(conv(s));
    }

    solve(arr);
    return 0;
}
