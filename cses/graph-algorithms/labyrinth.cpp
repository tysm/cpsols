#include <cpplib/stdinc.hpp>
#include <cpplib/graph/traversal/breadth-first-search.hpp>

ii get_coords(char dir){
    switch(dir){
        case 'U':
            return {-1, 0};
        case 'D':
            return {1, 0};
        case 'L':
            return {0, -1};
        case 'R':
            return {0, 1};
        default:
            assert(false);
            break;
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1193
    desync();
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    queue<ii> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 'A'){
                q.push({i, j});
                arr[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        int i = q.front().ff, j = q.front().ss;
        q.pop();

        char dirs[4] = {'U', 'D', 'L', 'R'};
        for(char dir:dirs){
            ii coords = get_coords(dir);

            int ki = i + coords.ff, kj = j + coords.ss;
            if(ki < 0 or ki >= n)
                continue;
            if(kj < 0 or kj >= m)
                continue;

            char cur = arr[ki][kj];
            if(!cur or (cur != '.' and cur != 'B'))
                continue;
            arr[ki][kj] = dir;

            if(cur == 'B'){
                cout << "YES" << endl;
                string ans;
                while(arr[ki][kj]){
                    ans += arr[ki][kj];
                    coords = get_coords(arr[ki][kj]);
                    ki -= coords.ff;
                    kj -= coords.ss;
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl << ans << endl;
                return 0;
            }
            q.push({ki, kj});
        }
    }
    cout << "NO" << endl;
    return 0;
}
