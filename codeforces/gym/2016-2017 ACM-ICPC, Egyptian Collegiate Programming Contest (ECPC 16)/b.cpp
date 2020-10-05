#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/floyd-warshall.hpp>

int32_t main(){
    ifstream cin("street.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, H, W;
        cin >> n >> H >> W;

        vi h(n+2), w(n+2), m(n+2), k(n+2);
        for(int i=1; i<=n; ++i)
            cin >> h[i] >> w[i] >> m[i] >> k[i];

        vvd dis(n+2, vd(n+2, LINF));
        dis[0][0] = dis[n+1][n+1] = 0;
        dis[0][n+1] = dis[n+1][0] = H;

        for(int i=1; i<=n; ++i){
            dis[i][i] = 0;

            dis[0][i] = dis[i][0] = m[i];
            dis[i][n+1] = dis[n+1][i] = H - (m[i] + h[i]);

            for(int j=i+1; j<=n; ++j){
                int y = min(abs(m[i] + h[i] - m[j]), abs(m[j] + h[j] - m[i]));
                int x = max((int)0, W - (w[i] + w[j]));

                double &d = dis[i][j];
                if(k[i] == k[j])
                    d = y;
                else if(m[i] > m[j] + h[j] or m[j] > m[i] + h[i])
                    d = sqrt(x*x + y*y);
                else
                    d = x;
                dis[j][i] = d;
            }
        }
        dis = floyd(dis);
        cout << fixed << setprecision(6) << dis[0][n+1] << endl;
    }
    return 0;
}
