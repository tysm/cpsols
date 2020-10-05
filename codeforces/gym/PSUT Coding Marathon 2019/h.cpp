#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

point<int> ctov(char c){
    c -= '1';
    return {dx[c], dy[c]};
}

vvi should(2);

bool cvseq(vi &seq){
    int n = seq.size();
    if(n == 3 and seq[0] == seq[2])
        return false;
    bool ok = false;
    for(int t:{0, 1}){
        int pos = 0;
        while(seq[0] != should[t][pos])
            pos++;
        int spos = pos;
        for(int i:seq){
            while(pos < should[t].size() and should[t][pos] != i)
                pos++;
        }
        if(pos <= spos+8)
            ok = true;
    }
    return ok;
}

int32_t main(){
    desync();

    for(int r=0; r<2; ++r){
        for(int i=0; i<8; ++i)
            should[0].eb(i);
        for(int i=7; i>=0; --i)
            should[1].eb(i);
    }

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<point<int> > pos(1);
    for(char c:s)
        pos.eb(pos.back()+ctov(c));

    vii arr;
    for(int i=0; i<n; ++i){
        int j=i+1;
        for(; j<n and s[i] == s[j]; ++j);
        arr.eb(s[i]-'1', j-i);
        i = j-1;
    }

    int ans = 0, cur = 0;
    for(int i=0; i<(int)arr.size()-2; ++i){
        set<point<int> > ini;
        for(int j=0; j<arr[i].ss; ++j)
            ini.ep(pos[cur+j]);

        int acc = 0;

        vi seq;
        for(int j=0; j<2; ++j){
            acc += arr[i+j].ss;
            seq.eb(arr[i+j].ff);
        }

        for(int j=i+2; j<min((int)arr.size(), i+9); ++j){
            seq.eb(arr[j].ff);
            if(cvseq(seq)){
                for(int k=1; k<=arr[j].ss; ++k){
                    if(ini.count(pos[cur+acc+k]))
                        ans++;
                }
            }
            acc += arr[j].ss;
        }

        cur += arr[i].ss;
    }
    cout << ans << endl;
    return 0;
}
