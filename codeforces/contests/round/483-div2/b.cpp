#include <cpplib/stdinc.hpp>

int di[] = {0, 0, -1, 1, -1, 1, -1, 1}, dj[] = {1, -1, 0, 0, 1, 1, -1, -1};

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(string &s:arr)
        cin >> s;

    bool ok = true;
    set<ii> vis;
    queue<ii> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr[i][j] == '*'){
                if(!vis.count(ii(i, j)))
                    q.ep(i, j);
                vis.ep(i, j);
            }
            else if(arr[i][j] == '.'){
                for(int k=0; k<8; ++k){
                    int ki = i+di[k], kj = j + dj[k];
                    if(ki < 0 or ki == n or kj < 0 or kj == m)
                        continue;
                    if(arr[ki][kj] == '*')
                        ok = false;
                }
            }
        }
    }

    vvi cnt(n, vi(m));
    while(!q.empty()){
        int i = q.front().ff, j = q.front().ss;
        q.pop();

        for(int k=0; k<8; ++k){
            int ki = i+di[k], kj = j + dj[k];
            if(ki < 0 or ki == n or kj < 0 or kj == m)
                continue;
            cnt[ki][kj]++;
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr[i][j] == '.' or arr[i][j] == '*')
                continue;
            if(arr[i][j] - '0' != cnt[i][j])
                ok = false;
        }
    }
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}
