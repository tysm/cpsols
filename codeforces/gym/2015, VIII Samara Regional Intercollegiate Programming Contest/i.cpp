#include <cpplib/stdinc.hpp>

int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

int dist(int x, int y, int xi, int yi){
    int dx = abs(xi-x), dy = abs(yi-y);
    return dx/2 + dx%2 + dy/2 + dy%2;
}

int32_t main(){
    desync();
    int x, y;
    cin >> x >> y;

    string s;
    cin >> s;

    int k;
    if(s == "LEFT")
        k = 3;
    else if(s == "RIGHT")
        k = 2;
    else if(s == "UP")
        k = 0;
    else
        k = 1;

    int n;
    cin >> n;
    pair<string, int> ans = {"0", LINF};
    for(int i=0; i<n; ++i){
        string sh;
        cin >> sh;
        int xi, yi;
        cin >> xi >> yi;

        int lo=1, hi=1e9, res = LINF;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int d = dist(xi, yi, x+di[k]*mid, y+dj[k]*mid);
            if(d <= mid){
                hi = mid-1;
                res = mid;
            }
            else
                lo = mid+1;
        }
        if(res < ans.ss)
            ans = {sh, res};
    }
    cout << ans.ff << endl;
    return 0;
}
