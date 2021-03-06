#include <cpplib/stdinc.hpp>

int tb[8][8];

/**
 * Breadth First Search
 *
 * Note: in orther to retrieve the shortest
 * path we can store the predecessor of each
 * vertex when a successful relaxation occurs.
 *
 * Time Complexity: O(n + m).
 * Where n is the size of the graph and m is the quantity of edges.
 */
void bfs(ii s){
    tb[s.ff][s.ss] = 0;
    queue<ii> q; q.push(s);

    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    while(!q.empty()){
        ii u = q.front(); q.pop();

        for(int i=0; i<8; ++i){
            int x = u.ff + dx[i];
            int y = u.ss + dy[i];
            if(x < 0 or y < 0 or x >=8 or y >= 8)
                continue;
            if(tb[x][y] != -1)
                continue;
            tb[x][y] = tb[u.ff][u.ss] + 1;
            q.push({x, y});
        }
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        char c;

        int sx, sy;
        cin >> c;
        sx = c-'a';
        cin >> c;
        sy = c-'1';

        memset(tb, -1, sizeof(tb));
        bfs({sx, sy});

        int ex, ey;
        cin >> c;
        ex = c-'a';
        cin >> c;
        ey = c-'1';

        cout << tb[ex][ey] << endl;
    }
    return 0;
}
