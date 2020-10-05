#include <cpplib/stdinc.hpp>

void solve(int &clr, vvi &ans, int x1, int y1, int x2, int y2, int x, int y){
    if(x2-x1 == 1){ // 2 x 2.
        for(int i=x1; i<=x2; ++i){
            for(int j=y1; j<=y2; ++j){
                if(!ans[i][j])
                    ans[i][j] = clr;
            }
        }
        clr++;
        return;
    }

    int midx = (x1+x2)/2, midy = (y1+y2)/2;

    int quad = 1;
    if(x <= midx){
        if(y <= midy)
            quad = 2;
    }
    else{
        if(y <= midy)
            quad = 3;
        else
            quad = 4;
    }

    if(quad == 1){
        ans[midx][midy] = ans[midx+1][midy] = ans[midx+1][midy+1] = clr++;
        solve(clr, ans, x1, midy+1, midx, y2, x, y); // 1
        solve(clr, ans, x1, y1, midx, midy, midx, midy); // 2
        solve(clr, ans, midx+1, y1, x2, midy, midx+1, midy); // 3
        solve(clr, ans, midx+1, midy+1,  x2, y2, midx+1, midy+1); // 4
    }
    else if(quad == 2){
        ans[midx][midy+1] = ans[midx+1][midy] = ans[midx+1][midy+1] = clr++;
        solve(clr, ans, x1, midy+1, midx, y2, midx, midy+1); // 1
        solve(clr, ans, x1, y1, midx, midy, x, y); // 2
        solve(clr, ans, midx+1, y1, x2, midy, midx+1, midy); // 3
        solve(clr, ans, midx+1, midy+1,  x2, y2, midx+1, midy+1); // 4
    }
    else if(quad == 3){
        ans[midx][midy+1] = ans[midx][midy] = ans[midx+1][midy+1] = clr++;
        solve(clr, ans, x1, midy+1, midx, y2, midx, midy+1); // 1
        solve(clr, ans, x1, y1, midx, midy, midx, midy); // 2
        solve(clr, ans, midx+1, y1, x2, midy, x, y); // 3
        solve(clr, ans, midx+1, midy+1,  x2, y2, midx+1, midy+1); // 4
    }
    else{
        ans[midx][midy+1] = ans[midx+1][midy] = ans[midx][midy] = clr++;
        solve(clr, ans, x1, midy+1, midx, y2, midx, midy+1); // 1
        solve(clr, ans, x1, y1, midx, midy, midx, midy); // 2
        solve(clr, ans, midx+1, y1, x2, midy, midx+1, midy); // 3
        solve(clr, ans, midx+1, midy+1,  x2, y2, x, y); // 4
    }
}

int di[] = {0, 0, 1, -1}, dj[] = {-1, 1, 0, 0};

void dfs(vvi &mat, vector<vector<char> > &ans, set<char> &mx, int i, int j, int clr){
    int n = mat.size();
    mat[i][j] = -2;
    for(int k=0; k<4; ++k){
        int ki = i+di[k], kj = j+dj[k];
        if(ki < 0 or kj < 0 or ki >= n or kj >= n)
            continue;
        if(mat[ki][kj] == clr)
            dfs(mat, ans, mx, ki, kj, clr);
        else if(mat[ki][kj] == 0)
            mx.ep(ans[ki][kj]);
    }
}

void paint(vvi &mat, vector<vector<char> > &ans, int i, int j, char clr){
    int n = mat.size();
    ans[i][j] = clr;
    mat[i][j] = 0;
    for(int k=0; k<4; ++k){
        int ki = i+di[k], kj = j+dj[k];
        if(ki < 0 or kj < 0 or ki >= n or kj >= n)
            continue;
        if(mat[ki][kj] != -2)
            continue;
        paint(mat, ans, ki, kj, clr);
    }
}

void print(vvi &mat, int x, int y){
    int n = mat.size();

    vector<vector<char> > ans(n, vector<char>(n, -1));

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(mat[i][j] <= 0)
                continue;

            set<char> mx;
            dfs(mat, ans, mx, i, j, mat[i][j]);

            char clr = 'A';
            while(mx.count(clr))
                clr++;

            paint(mat, ans, i, j, clr);
        }
    }

    ans[x][y] = '.';
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << ans[i][j];
        cout << endl;
    }
}

int32_t main(){
    desync();
    int n, x, y;
    cin >> n >> x >> y;
    if(n == 1){
        cout << '.' << endl;
        return 0;
    }

    x--;
    y--;

    vvi mat(n, vi(n));
    mat[x][y] = -1;

    int clr = 1;
    solve(clr, mat, 0, 0, n-1, n-1, x, y);

    print(mat, x, y);
    return 0;
}
