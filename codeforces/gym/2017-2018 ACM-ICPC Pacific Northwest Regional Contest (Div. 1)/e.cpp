#define double long double
#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

int N, X;
double V;
vector<tuple<int, int, double> > arr;

double degrees(double ang){
    return 180*ang/PI;
}

double check(double ang, point<double> w){
    int x = 0;
    double y = 0;
    for(auto [l, r, v]:arr){
        int d = l - x;
        y += tan(ang)*d;

        point<double> vec(0, v);

        d = r-l;
        y += tan(polar_angle(w + vec))*d;

        x = r;
    }
    if(x < X){
        int d = X - x;
        y += tan(ang)*d;
    }
    return abs(y);
}

double solve(double ang, point<double> w){
    cerr << fixed << setprecision(3) << endl;

    int x = 0;
    double res = 0, dis = 0;
    for(auto [l, r, v]:arr){
        int d = l - x;
        res += abs(d/cos(ang))/V;
        dis += abs(d/cos(ang));

        point<double> vec(0, v);

        d = r-l;
        res += abs(d/cos(polar_angle(w + vec)))/norm(w + vec);
        dis += abs(d/cos(polar_angle(w + vec)));

        x = r;
    }
    if(x < X){
        int d = X - x;
        res += abs(d/cos(ang))/V;
        dis += abs(d/cos(ang));
    }
    return res;
}

int32_t main(){
    desync();
    cin >> N >> X >> V;

    for(int i=0; i<N; ++i){
        int li, ri;
        double vi;
        cin >> li >> ri >> vi;
        arr.eb(li, ri, vi);
    }

    double lo = -PI/2, hi = PI/2;
    for(int rep=0; rep<300; ++rep){
        double m1 = lo + (hi-lo)/3, m2 = hi - (hi-lo)/3;

        point<double> w1(cos(m1)*V, sin(m1)*V), w2(cos(m2)*V, sin(m2)*V);

        double d1 = check(m1, w1), d2 = check(m2, w2);
        if(d1 < d2)
            hi = m2;
        else
            lo = m1;
    }

    double res = lo + (hi-lo)/2;

    point<double> w(cos(res)*V, sin(res)*V);

    double ans = solve(res, w);

    double aux = 60*PI/180.0;
    point<double> auxw(cos(aux)*V, sin(aux)*V);
    if(ans*V > 2*X or abs(check(res, w)) > 1e-6)
        cout << "Too hard" << endl;
    else
        cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
