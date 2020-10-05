#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

double sarea(point<int> a, point<int> b, point<int> c){
    return ((b-a)^(c-b)).z/2.0L;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<point<int> > arr(n);
    for(auto &p:arr)
        cin >> p.x >> p.y;

    double res = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            double pos = 0, neg = 0;
            for(int k=0; k<n; ++k){
                if(k == i or k == j)
                    continue;
                double s = sarea(arr[i], arr[j], arr[k]);
                if(s > 0)
                    pos = max(pos, s);
                else
                    neg = max(neg, -s);
            }
            if(abs(neg) < EPS or abs(pos) < EPS)
                continue;
            res = max({res, pos + neg});
        }
    }
    cout << fixed << setprecision(16) << res << endl;
    return 0;
}
