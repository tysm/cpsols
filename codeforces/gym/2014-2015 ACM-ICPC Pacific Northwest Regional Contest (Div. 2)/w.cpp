#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geometry/point.hpp>
#include <cpplib/graph/shortest-path/floyd-warshall.hpp>

int32_t main(){
    desync();
    int m;
    cin >> m;
    for(int t=1; t<=m; ++t){
        cout << "Case " << t << ':' << endl;
        int n;
        cin >> n;
        vector<point<int> > arr(n);
        map<string, int> stri;
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            stri[s] = i;
            cin >> arr[i].x >> arr[i].y >> arr[i].z;
        }
        vvd dis(n, vd(n, LINF));
        for(int i=0; i<n; ++i){
            dis[i][i] = 0;
            for(int j=i+1; j<n; ++j)
                dis[i][j] = dis[j][i] = distance(arr[i], arr[j]);
        }
        int w;
        cin >> w;
        for(int i=0; i<w; ++i){
            string s1, s2;
            cin >> s1 >> s2;
            int j = stri[s1], k = stri[s2];
            dis[j][k] = 0;
        }
        dis = floyd(dis);
        int q;
        cin >> q;
        while(q--){
            string s1, s2;
            cin >> s1 >> s2;
            int j = stri[s1], k = stri[s2];
            cout << "The distance from " << s1 << " to " << s2 << " is " << (int)round(dis[j][k]) << " parsecs." << endl;
        }
    }
    return 0;
}
