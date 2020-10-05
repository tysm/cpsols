#include <bits/stdc++.h>
#define int int32_t
#define all(x) x.begin(), x.end()
#define endl "\n"
using namespace std;

struct point {
    int x, y;

    int64_t cross(point &other) const
    {
        return (int64_t)x*other.y - (int64_t)y*other.x;
    }

    bool operator<(const point &other){
        return tie(x, y) < tie(other.x, other.y);
    }

    bool operator==(const point &other){
        return tie(x, y) == tie(other.x, other.y);
    }
};

bool cw(point &a, point &b, point &c)
{
    point d;
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    point e;
    e.x = c.x - b.x;
    e.y = c.y - b.y;
    return d.cross(e) < 0;
}

bool ccw(point &a, point &b, point &c)
{
    point d;
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    point e;
    e.x = c.x - b.x;
    e.y = c.y - b.y;
    return d.cross(e) > 0;
}

vector<point> convex_hull(vector<point> &pts){
    int n = pts.size();
    if(n == 1)
        return pts;
    sort(all(pts));

    point p1 = pts[0], p2 = pts[n-1];
    vector<point> up(1, p1), down(1, p1);
    for(int i=1; i<n; ++i){
        if(i == n-1 or cw(p1, pts[i], p2)){
            while(up.size() >= 2 and !cw(up[up.size()-2], up[up.size()-1], pts[i]))
                up.pop_back();
            up.emplace_back(pts[i]);
        }
        if(i == n-1 or ccw(p1, pts[i], p2)){
            while(down.size() >= 2 and !ccw(down[down.size()-2], down[down.size()-1], pts[i]))
                down.pop_back();
            down.emplace_back(pts[i]);
        }
    }
    vector<point> res;
    for(auto &p:down)
        res.emplace_back(p);
    for(int i = up.size()-2; i>0; --i)
        res.emplace_back(up[i]);
    return res;
}

int64_t area(point &a, point &b, point &c, point &d){
    return abs(a.cross(b) + b.cross(c) + c.cross(d) + d.cross(a));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> arr(n);
    for(int i=0; i<n; ++i)
        cin >> arr[i].x >> arr[i].y;

    vector<point> hull = convex_hull(arr);
    int m = hull.size();

    cout << fixed << setprecision(1);
    if(m <= 2){
        cout << 0.0 << endl;
        return 0;
    }

    int64_t ans = 0;
    if(m == 3){
        for(int i=0; i<n; ++i){
            bool ok = true;
            for(int j=0; j<3; ++j)
                ok &= !(arr[i] == hull[j]);
            if(!ok)
                continue;
            ans = max(ans, area(hull[0], hull[1], hull[2], arr[i]));
            ans = max(ans, area(hull[0], hull[1], arr[i], hull[2]));
            ans = max(ans, area(hull[0], arr[i], hull[1], hull[2]));
        }
    }
    else{
        point IJ;
        auto area = [&](point &a, point &b){
            point d;
            d.x = b.x - a.x;
            d.y = b.y - a.y;
            return abs(IJ.cross(d));
        };

        for(int i=0; i<m-3; ++i){
            int k = i+1, j = i+2, l = i+3;
            for(; j<m-1; ++j){
                IJ.x = hull[j].x - hull[i].x;
                IJ.y = hull[j].y - hull[i].y;

                if(j == l)
                    l++;

                while(k+1 < j and area(hull[j], hull[k+1]) > area(hull[j], hull[k]))
                    k++;

                while(l+1 < m and area(hull[j], hull[l+1]) > area(hull[j], hull[l]))
                    l++;

                ans = max(ans, area(hull[j], hull[k]) + area(hull[j], hull[l]));
            }
        }
    }
    cout << ans*0.5L << endl;
    return 0;
}
