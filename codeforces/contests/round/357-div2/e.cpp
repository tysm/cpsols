#define double long double
#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/circle.hpp>

using pdd = pair<double, double>;

int32_t main(){
    desync();
    point<int> ini;
    int v, T;
    cin >> ini.x >> ini.y >> v >> T;

    int n;
    cin >> n;

    bool ok = false;
    vector<circle<int> > plts;
    for(int i=0; i<n; ++i){
        point<int> p;
        int r;
        cin >> p.x >> p.y >> r;
        plts.eb(p, r);

        if(count(plts.back(), ini))
            ok = true; // already in the shadow.
    }
    if(ok)
        cout << 1 << endl;
    else{
        circle<int> coc(ini, v*T);

        vector<pdd> angs;
        for(int i=0; i<n; ++i){
            if(coc.r > distance(ini, plts[i].c) - EPS){
                auto res = plts[i].tangents(coc.c);

                pdd cur;
                cur.ff = polar_angle(get<1>(res) - ini);
                cur.ss = polar_angle(get<0>(res) - ini);
                if(cur.ff >= cur.ss + EPS){
                    angs.eb(cur.ff, 2*PI-EPS);
                    angs.eb(0, cur.ss);
                }
                else
                    angs.eb(cur);
            }
            else if(intersect(coc, plts[i])){
                auto res = intersection(coc, plts[i]);

                pdd cur;
                cur.ff = polar_angle(get<0>(res) - ini);
                cur.ss = polar_angle(get<1>(res) - ini);
                if(cur.ff >= cur.ss + EPS){
                    angs.eb(cur.ff, 2*PI-EPS);
                    angs.eb(0, cur.ss);
                }
                else
                    angs.eb(cur);
            }
        }
        sort(all(angs));

        vector<pdd> res;
        for(pdd &i:angs){
            if(res.empty() or res.back().ss <= i.ff - EPS)
                res.eb(i);
            else
                res.back().ss = max(res.back().ss, i.ss);
        }
        double ans = 2*PI - EPS;
        for(pdd &i:res)
            ans -= i.ss - i.ff + EPS;
        cout << fixed << setprecision(16) << 1 - ans/(2*PI - EPS) << endl;
    }
    return 0;
}
